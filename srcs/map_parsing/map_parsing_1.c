/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:22:58 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/30 15:18:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui controle si il y a au moins 1 collectible et qui stock l'info
// dans la structure map.
// 
// -----------------------------------------------------------------------------
// 
// Double boucle pour parcourir le double tableau.
// Si le caractere est egale a "C" -> nb_of_collectible++ et save le nombre de
// collectibles dans la structure map.
// Si nob_of_collectible est inferieur a 1 -> return (1)

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
	game->map.collectible_counter = nb_of_collectable;
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui controle si il y a uniquement les elements autorises dans la map
// 
// -----------------------------------------------------------------------------
// 
// Double boucle pour parcourir le double tableau.
// Si il y a un autre caractere que ceux autorises -> return (1)

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
