/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/23 00:46:46 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
// Plan
// itialisation_struct_graph
// itialisation_hooks_&_input
//
// int i = 0;
	// int j = 0;
	// while (game->map.tab_map[i])
	// {
	// 	j = 0;
	// 	while (game->map.tab_map[i][j])
	// 	{
	// 		ft_put_image(game, i, j);
	// 		j++;
	// 	}
	// 	i++;	
	// }

/* void	ft_put_image(t_game *game, int i, int j)
	{
		if ((game->map.tab_map)[i][j] == '1')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.wall.img, ELEM_SIZE*j, ELEM_SIZE*i);
		if (game->map.tab_map[i][j] == '0')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.floor.img, ELEM_SIZE*j, ELEM_SIZE*i);	
		if (game->map.tab_map[i][j] == 'C')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.c.img, ELEM_SIZE*j, ELEM_SIZE*i);	
		if (game->map.tab_map[i][j] == 'P')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_loose.img, ELEM_SIZE*j, ELEM_SIZE*i);
		if (game->map.tab_map[i][j] == 'P')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_win.img, ELEM_SIZE*j, ELEM_SIZE*i);
		if (game->map.tab_map[i][j] == 'E')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e_close.img, ELEM_SIZE*j, ELEM_SIZE*i);
		if (game->map.tab_map[i][j] == 'E')
			mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e_open.img, ELEM_SIZE*j, ELEM_SIZE*i);
	} */

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
	if (game->graph.win_ptr /* && game->graph.render_again == 1 */) // secu si il  ya eu une probleme avec la window + flag pour eviter de refrensh a chaque fram alors aucun input a ete press
	{
		if (!ft_display_map(game))
			return (0);
		// game->graph.render_again = 0; // pour signaler que ca ete mit a jour car le frag etait == 1, il passe a zero pour eviter les refrensh pour rien.
	}
	return (1);
}
int	ft_display_map(t_game *game)
{
	long int	x;
	long int	y;
	y = 0;
	while (game->map.tab_map[y])
	{
		x = 0;
		while (game->map.tab_map[y][x])
		{//printf("y_player : %ld\nx_player : %ld\n y : %ld\n x : %ld\n", game->player.y, game->player.x, y, x);
			if (game->player.y_player == y && game->player.x_player == x)
				ft_display_player(game);
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
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_loose.img, ELEM_SIZE * game->player.y_player, ELEM_SIZE * game->player.x_player);
	else
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_win.img, ELEM_SIZE * game->player.y_player, ELEM_SIZE * game->player.x_player);
}

void	ft_display_elem(t_game *game, long int x, long int y)
{
	if ((game->map.tab_map)[y][x] == '1')
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.wall.img, ELEM_SIZE * y, ELEM_SIZE * x);
	else if (game->map.tab_map[y][x] == '0')
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.floor.img, ELEM_SIZE * y, ELEM_SIZE * x);	
	else if (game->map.tab_map[y][x] == 'C')
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.c.img, ELEM_SIZE * y, ELEM_SIZE * x);	
	if (game->map.tab_map[y][x] == 'E' && game->map.collectible_counter != 0)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e_close.img, ELEM_SIZE * y, ELEM_SIZE * x);
	else
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e_open.img, ELEM_SIZE * y, ELEM_SIZE * x);
}