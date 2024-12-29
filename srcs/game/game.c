/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 05:27:25 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

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
	game->player.p_loose.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_loose.xpm", &game->player.p_loose.l, &game->player.p_loose.h);
	if (!game->player.p_loose.img)
		return (0);
	game->player.p_win.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_win.xpm", &game->player.p_win.l, &game->player.p_win.h);
	if (!game->player.p_win.img)	
		return (0);
	game->graph.e_open.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/e_open.xpm", &game->graph.e_open.l, &game->graph.e_open.h);
	if (!game->graph.e_open.img)
		return (0);
	game->player.p_and_e.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_and_e.xpm", &game->player.p_and_e.l, &game->player.p_and_e.h);
	if (!game->graph.e_open.img)
		return (0);
	return (1);
}
int	ft_refresh_display(t_game *game)
{
	if (game->graph.win_ptr && game->graph.flag_refresh == 0) // secu, si il y a eu un probleme avec la window + flag pour eviter de refresh a chaque frame alors aucun input a ete press
	{
		if (!ft_display(game))
			return (0);
		game->graph.flag_refresh = 1; // pour signaler que ca ete mis a jour car le frame etait == 1, il passe a zero pour eviter les refresh pour rien.
	}
	return (1);
}
// Les conditions des deux boucles ont le nombre de lignes et de colones que y et x doivent rester strictement inferieur pour ne pas depasser l'indexe max.
// Ces conditions sont utilisees car si on utilise -> while (tab_map[y][x]) comme condition, il y a un '\n' en fin de chaque ligne avant le '\0'. Cela pose probleme.
int	ft_display(t_game *game)
{
	long int	x;
	long int	y;

	y = 0;
	while (y < game->map.line_map)
	{
		x = 0;
		while (x < game->map.col_map)
		{
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
// transmit par la fonction mere (ft_display) avec le defilement dans
// le double tableau map_tab.
void	ft_display_player(t_game *game)
{
	if (game->map.tab_map[game->player.y_player][game->player.x_player] == 'E' && game->map.collectible_counter != 0)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->player.p_and_e.img, game->player.x_player * ELEM_SIZE, game->player.y_player * ELEM_SIZE);
	else if (game->map.collectible_counter == 0)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->player.p_win.img, game->player.x_player * ELEM_SIZE, game->player.y_player * ELEM_SIZE);
	else
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->player.p_loose.img, game->player.x_player * ELEM_SIZE, game->player.y_player * ELEM_SIZE);
		
}

void	ft_display_elem(t_game *game, long int x, long int y)
{
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
	else if (game->map.tab_map[y][x] == 'P' && game->player.p_loose.img && game->player.p_win.img && game->player.p_and_e.img)// cela met a l'emplacement du player initial, un "floor". Apres le 1er deplacement, les coordonnees du player sont stocker et mise a jour dans la struct du player tout au long de la game. Plus besoin du 'P' initial.
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.floor.img, x * ELEM_SIZE, y * ELEM_SIZE);	
}
