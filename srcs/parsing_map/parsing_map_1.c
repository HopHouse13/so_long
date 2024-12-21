/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:22:58 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/20 17:04:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_other_elem(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.tab_map[i])
	{
		j = 0;
		while (game->map.tab_map[i][j])
		{
			if (game->map.tab_map[i][j] != 'P' &&
				game->map.tab_map[i][j] != 'E' &&
				game->map.tab_map[i][j] != 'C' &&
				game->map.tab_map[i][j] != '0' &&
				game->map.tab_map[i][j] != '1' &&
				game->map.tab_map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
