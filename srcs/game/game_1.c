/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:26:52 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 19:22:33 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

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
int	ft_movement_management(int keysym, t_game *game)
{
	if ((keysym == XK_w || keysym == XK_Up) && (ft_movement_possible('^', game)))
		game->player.y_player -= 1;
	else if ((keysym == XK_s || keysym == XK_Down) && (ft_movement_possible('v', game)))
		game->player.y_player += 1;
	else if ((keysym == XK_a || keysym == XK_Left) && (ft_movement_possible('<', game)))
		game->player.x_player -= 1;
	else if ((keysym == XK_d || keysym == XK_Right) && (ft_movement_possible('>', game)))
		game->player.x_player += 1;
	ft_tile_state_change(game);
	game->graph.flag_refresh = 0; // il y a eu un mouvement, on change l'etat du flag "flag_refresh" pour que mlx_loop_hook actualise l'affichage.
	return (0);
}

// La derniere condition de chaque 'if' est une securite supplementaire au cas 
// ou la condition avecles wall ne fonctionne pas. Cette derniere condition
// interdit au player de sortir des coordonnees de la map
// (evite aussi les seg. fault)
int	ft_movement_possible(char direction, t_game *game)
{
	if (direction == '^' && game->map.tab_map[game->player.y_player - 1][game->player.x_player] != '1' && game->player.y_player - 1 >= 0)
		return(ft_print_movement_nb(game));
	else if (direction == 'v' && game->map.tab_map[game->player.y_player + 1][game->player.x_player] != '1' && game->player.y_player + 1 < game->map.line_map)
		return(ft_print_movement_nb(game));
	else if (direction == '<' && game->map.tab_map[game->player.y_player][game->player.x_player - 1] != '1' && game->player.x_player - 1 >= 0)
		return(ft_print_movement_nb(game));
	else if (direction == '>' && game->map.tab_map[game->player.y_player][game->player.x_player + 1] != '1' && game->player.x_player + 1 < game->map.col_map)
		return(ft_print_movement_nb(game));
	return (0);
}

int	ft_print_movement_nb(t_game *game)
{
	game->player.movements++;
	write (1,"Move N. ", 8);
	ft_putnbr_and_return_to_line(game->player.movements);
	return (1);
}

void	ft_tile_state_change(t_game *game)
{
	if (game->map.tab_map[game->player.y_player][game->player.x_player] == 'C')
	{
		game->map.tab_map[game->player.y_player][game->player.x_player] = '0';
		game->map.collectible_counter--;
	}
	else if (game->map.tab_map[game->player.y_player][game->player.x_player] == 'E' && game->map.collectible_counter == 0)
		mlx_loop_end(game->graph.mlx_ptr);
}

