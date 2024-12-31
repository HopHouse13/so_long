/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:29:13 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/31 19:28:02 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int	ft_cross_management(t_game *game)
{
	if (game->graph.win_ptr)
		mlx_loop_end(game->graph.mlx_ptr);
	return (0);
}
