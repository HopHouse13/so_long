/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:22:58 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 05:18:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_collectible_exists(t_game *game)
{
	int	i;
	int	j;
	int	nb_of_collectable;

	nb_of_collectable = 0;
	i = 0;
	while (game->map.tab_map[i])
	{
		j = 0;
		while (game->map.tab_map[i][j])
		{
			if (game->map.tab_map[i][j] == 'C')
				nb_of_collectable++;
			j++;
		}
		i++;
	}
	if (nb_of_collectable < 1)
		return (1);
	game->map.collectible_counter = nb_of_collectable; // itialisation du nb de collectives dans la variable "map"
	return (0);
}

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
				game->map.tab_map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
