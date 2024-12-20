/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:14:23 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/19 14:39:06 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_flood_fill_manag(t_game *game)
{
	t_map	map_ff;
	
	// map_ff = malloc(sizeof(t_map));
	// if (map_ff)
	// 	return (0);
	map_ff = ft_initialisation_struct_ff(game, map_ff);
	ft_flood_fill(game, map_ff, map_ff.line_player, map_ff.col_player);
	if (map_ff.collectible_counter != 0 || map_ff.exit_counter != 0)
	{
		if (map_ff.collectible_counter != 0)
			ft_error_messages_ff(1);
		if (map_ff.exit_counter != 0)
			ft_error_messages_ff(2);
		ft_free(game);
		/* ft_free_double_tab(map_ff.tab_map);
		free(game->map.ff);
		ft_free_double_tab(game->map.tab_map);
		free(game); */
		return (0);
	}
	return (1);
}
