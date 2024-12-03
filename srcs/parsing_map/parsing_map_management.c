/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:10:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/03 23:35:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* 	6 -> map non carre
	7 -> map non entouree de mur
	8 -> manque le player (P)
	9 -> manque la sortie (E)
	10 -> manque un collectible (C) */

	// faire un double tableau avec les lignes et collones puis l'envoyer aux fonctions de check

int	ft_map_parsing_manag(char *file, t_game *map)
{
	int		code_error;
	
	map->tab_map = ft_make_tab_map(file, map->tab_map);
	// int	i = -1;
	// while (map->tab_map[++i]) // pour verifier
	// 	printf("%s", map->tab_map[i]); 
	 code_error = 0;
	if (ft_rectangular(map->tab_map) != 0)
		code_error = 6;
	else if (ft_surrounded_by_walls(map->tab_map) != 0)
		code_error = 7;
	else if (ft_player_exists(map->tab_map) != 0)
		code_error = 8;
	else if (ft_exit_exists(map->tab_map) != 0)
		code_error = 9;
	else if (ft_collectible_exists(map->tab_map) != 0)
		code_error = 10;
	if (code_error != 0)
	{
		ft_error_messages_manag(code_error);
		return (0);
	}
	return (1);
}
