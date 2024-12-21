/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:10:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/20 20:32:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* 	6 -> map non carre
	7 -> map non entouree de mur
	8 -> manque le player (P)
	9 -> manque la sortie (E)
	10 -> manque un collectible (C) 
	11 -> autre caractere que les caracteres autorises */

	// faire un double tableau avec les lignes et collones puis l'envoyer 
	// aux fonctions de check

int	ft_map_parsing_manag(char *file, t_game *game)
{
	int		code_error;
	
	ft_initialisation_struct_map(game);
	ft_make_tab_map(file, game);
	code_error = 0;
	if (ft_rectangular(game) != 0)
		code_error = 6;
	else if (ft_surrounded_by_walls(game) != 0)
		code_error = 7;
	else if (ft_player_exists(game) != 0)
		code_error = 8;
	else if (ft_exit_exists(game) != 0)
		code_error = 9;
	else if (ft_collectible_exists(game) != 0)
		code_error = 10;
	else if (ft_other_elem(game) != 0)
		code_error = 11;
	if (code_error != 0)
	{
		ft_error_messages_file_and_map(code_error);
		ft_free_double_tab(game->map.tab_map);
		return (0);
	}

	return (1);
}
