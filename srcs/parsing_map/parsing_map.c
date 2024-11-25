/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:10:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/25 19:12:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* 	6 -> map non carre
	7 -> map non entouree de mur
	8 -> manque le player (P)
	9 -> manque la sortie (E)
	10 -> manque un collectible (C) */

/* int	ft_map_parsing_management(char *map) // map non carre (maybe arg d'entree -> double tableau)
{
	if (ft_rectangular(map) != 0)
		return (ft_rectangular(map));
	else if (ft_surrounded_by_walls(map) != 0)
		return (ft_surrounded_by_walls(map));
	else if (ft_player_exists(map) != 0)
		return (ft_player_exists(map));
	else if (ft_exit_exists(map) != 0)
		return (ft_exit_exists(map));
	else if (ft_collectible_exists(map) != 0)
		return (ft_collectible_exists(map));
	return (0);
} */