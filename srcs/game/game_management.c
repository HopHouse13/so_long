/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:25:11 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 05:25:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_game_start_management(t_game *game)
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
	return (1);
}