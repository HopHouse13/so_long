/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:10:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 00:43:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* 	6 -> map non carre
	7 -> map non entouree de mur
	8 -> manque le player (P)
	9 -> manque la sortie (E)
	10 -> manque un collectible (C) */

	// faire un double tableau avec les lignes et collones puis l'envoyer 
	// aux fonctions de check

int	ft_map_parsing_manag(char *file, t_game *map)
{
	int		code_error;

	ft_initialisation_struct_map(map);
	ft_make_tab_map(file, map);
	code_error = 0;
	if (ft_rectangular(map) != 0)
		code_error = 6;
	else if (ft_surrounded_by_walls(map) != 0)
		code_error = 7;
	else if (ft_player_exists(map) != 0)
		code_error = 8;
	else if (ft_exit_exists(map) != 0)
		code_error = 9;
	else if (ft_collectible_exists(map) != 0)
		code_error = 10;
	if (code_error != 0)
	{
		ft_error_messages_manag(code_error);
		return (0);
	}
	return (1);
}
