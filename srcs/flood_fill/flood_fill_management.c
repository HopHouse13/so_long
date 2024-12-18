/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:14:23 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/18 23:51:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_flood_fill_manag(t_game *game)
{
	game->map.ff = malloc(sizeof(t_map));
	if (!game->map.ff)
		return (0);
	ft_initialisation_struct_ff(game);
	ft_flood_fill(game, game->map.ff->line_player, game->map.ff->col_player);
	if (game->map.ff->collectible_counter != 0 || game->map.ff->exit_counter != 0)
	{
		if (game->map.ff->collectible_counter != 0)
			ft_error_messages_ff(1);
		if (game->map.ff->exit_counter != 0)
			ft_error_messages_ff(2);
		ft_free_double_tab(game->map.ff->tab_map);
		free(game->map.ff);
		ft_free_double_tab(game->map.tab_map);
		free(game);
		return (0);
	}
	return (1);
}
