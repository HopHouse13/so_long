/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/24 01:04:25 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// loop_hook (need mlx_ptr)
// hook (need win_ptr)
int		ft_so_long(t_game *game)
{
	game->graph.mlx_ptr = mlx_init();
	if (!game->graph.mlx_ptr)
		return (0);
	game->graph.win_ptr = mlx_new_window(game->graph.mlx_ptr, game->map.col_map * ELEM_SIZE, game->map.line_map * ELEM_SIZE, "Petit cercle deviendra carre");
	if (!game->graph.win_ptr)
		return (0);
	if (!ft_itialisation_img(game))
		return (0);	
	mlx_loop_hook(game->graph.mlx_ptr, &ft_refresh_display, game);
	mlx_hook(game->graph.win_ptr, KeyPress, KeyPressMask, &ft_input_management, game);
	mlx_hook(game->graph.win_ptr, DestroyNotify, StructureNotifyMask, &ft_cross_management, game);
	mlx_loop(game->graph.mlx_ptr);
	return (0);
}
	


int	ft_itialisation_img(t_game *game)
{
	game->graph.wall.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/wall.xpm", &game->graph.wall.l, &game->graph.wall.h);
	if (!game->graph.wall.img)
		return (0);
	game->graph.floor.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/floor.xpm", &game->graph.floor.l, &game->graph.floor.h);
	if (!game->graph.floor.img)
		return (0);
	game->graph.c.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/c.xpm", &game->graph.c.l, &game->graph.c.h);
	if (!game->graph.c.img)
		return (0);
	game->graph.e_close.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/e_close.xpm", &game->graph.e_close.l, &game->graph.e_close.h);
	if (!game->graph.e_close.img)
		return (0);
	game->graph.p_loose.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_loose.xpm", &game->graph.p_loose.l, &game->graph.p_loose.h);
	if (!game->graph.p_loose.img)
		return (0);
	game->graph.p_win.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_win.xpm", &game->graph.p_win.l, &game->graph.p_win.h);
	if (!game->graph.p_win.img)	
		return (0);
	game->graph.e_open.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/e_open.xpm", &game->graph.e_open.l, &game->graph.e_open.h);
	if (!game->graph.e_open.img)
		return (0);
	return (1);
}
int	ft_refresh_display(t_game *game)
{
	if (game->graph.win_ptr && game->graph.flag_refresh == 0) // secu, si il y a eu un probleme avec la window + flag pour eviter de refresh a chaque frame alors aucun input a ete press
	{
		if (!ft_display_map(game))
			return (0);
		game->graph.flag_refresh = 1; // pour signaler que ca ete mis a jour car le frame etait == 1, il passe a zero pour eviter les refresh pour rien.
	}
	return (1);
}
int	ft_display_map(t_game *game)
{
	long int	x;
	long int	y;

	y = 0;
	while (y < game->map.line_map)
	{
		x = 0;
		while (x < game->map.col_map)
		{//printf("\n y : [%ld]\tline : {%ld}\n x : [%ld]\tcol : {%ld}\n", y, game->map.line_map, x, game->map.col_map);
			if (game->player.y_player == y && game->player.x_player == x)
			{
				ft_display_player(game);
			}
			else
				ft_display_elem(game, x, y);
			x++;
		}
		y++;
	}
	return(1);
}
// Fonction a part pour afficher le player car c'est le seul element qui change
// de position. La mise a jour des coordonnees du player sont stockees dans la
// structure "player", "y", "x".
// Contrairement aux autres coordonnees des elements qui sont dirrectment
// transmit par la fonction mere (ft_display_map) avec le defilement dans
// le double tableau map_tab.
void	ft_display_player(t_game *game)
{
	if (game->map.collectible_counter != 0)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_loose.img, game->player.x_player * ELEM_SIZE, game->player.y_player * ELEM_SIZE);
	else
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_win.img, game->player.x_player * ELEM_SIZE, game->player.y_player * ELEM_SIZE);
}

void	ft_display_elem(t_game *game, long int x, long int y)
{ // printf("%c", (game->map.tab_map)[y][x]);
	if ((game->map.tab_map)[y][x] == '1' && game->graph.wall.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.wall.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == '0' && game->graph.floor.img) 
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.floor.img, x * ELEM_SIZE, y * ELEM_SIZE);	
	else if (game->map.tab_map[y][x] == 'C' && game->graph.c.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.c.img, x * ELEM_SIZE, y * ELEM_SIZE);	
	else if (game->map.tab_map[y][x] == 'E' && game->map.collectible_counter != 0 && game->graph.e_close.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e_close.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == 'E' && game->map.collectible_counter == 0 && game->graph.e_open.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e_open.img, x * ELEM_SIZE, y * ELEM_SIZE);
}
int	ft_input_management(int keysym, t_game *game)
{
	if (game->graph.win_ptr)
	{
		if (keysym == XK_Escape) // bouton esc
			mlx_loop_end(game->graph.mlx_ptr);
		else
			ft_movement_management(keysym, game);
	}
	return (0);
}
int	ft_movement_management(int keysym,t_game *game)
{
	if (keysym == XK_w && ft_movement_possible('^', game))
		game->player.y_player -= 1;
	else if (keysym == XK_s && ft_movement_possible('v', game))
		game->player.y_player += 1;
	else if (keysym == XK_a && ft_movement_possible('<', game))
		game->player.x_player -= 1;
	else if (keysym == XK_d && ft_movement_possible('>', game))
		game->player.x_player += 1;
	game->graph.flag_refresh = 0;
	return (0);
}
int	ft_movement_possible(char direction, t_game *game)
{//printf(">>>>>>>>>>>>>>>>> %c\n", game->map.tab_map[game->player.y_player - 1][game->player.x_player]);
	if (direction == '^' && game->map.tab_map[game->player.y_player - 1][game->player.x_player] != 1 && game->player.y_player - 1 >= 0)
		return(ft_print_movement_nb(game));
	else if (direction == 'v' && game->map.tab_map[game->player.y_player + 1][game->player.x_player] != 1 && game->player.y_player + 1 < game->map.line_map)
		return(ft_print_movement_nb(game));
	else if (direction == '<' && game->map.tab_map[game->player.y_player][game->player.x_player - 1] != 1 && game->player.x_player - 1 >= 0)
		return(ft_print_movement_nb(game));
	else if (direction == '>' && game->map.tab_map[game->player.y_player][game->player.x_player + 1] != 1 && game->player.x_player + 1 < game->map.col_map)
		return(ft_print_movement_nb(game));
	return (0);
}

int	ft_print_movement_nb(t_game *game)
{
	game->player.movements++;
	write (1, "move N.", 7);
	ft_putnbr(game->player.movements);
	write(1, "\n", 1);
	return (1);
}

int	ft_cross_management(t_game *game)
{
	if (game->graph.win_ptr)
		mlx_loop_end(game->graph.win_ptr);
	return (0);
}

