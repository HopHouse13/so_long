/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:14:23 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 00:28:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_flood_fill_manag(t_game *map)
{
	map->ff = malloc(sizeof(t_game));
	if (!map->ff)
		return (0);
	ft_initialisation_struct_ff(map);
	int i = -1;
	while (map->ff->tab_map[++i])
		printf("%s", map->ff->tab_map[i]);
	printf("-----------------------\n");
	ft_flood_fill(map, map->ff->line_player, map->ff->col_player);
	printf("-----------------------\n");
	i = -1;
	while (map->ff->tab_map[++i])
		printf("%s", map->ff->tab_map[i]);
	if (map->ff->collectible_counter != 0 || map->ff->exit_counter != 0)
	{
		if (map->ff->collectible_counter != 0)
			ft_error_messages_manag(11);
		if (map->ff->exit_counter != 0)
			ft_error_messages_manag(12);
		return (0);
	}
	return (1);
}
