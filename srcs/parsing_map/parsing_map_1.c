/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:22:58 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 19:06:57 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_other_elem(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab_map[i])
	{
		j = 0;
		while (map->tab_map[i][j])
		{
			if (map->tab_map[i][j] != 'P' &&
				map->tab_map[i][j] != 'E' &&
				map->tab_map[i][j] != 'C' &&
				map->tab_map[i][j] != '0' &&
				map->tab_map[i][j] != '1' &&
				map->tab_map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
