/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:10:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/30 15:11:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui gere les differentes etapes du controle de la map.
// 
// -----------------------------------------------------------------------------
// 
// 6 -> map non rectangulaire
// 7 -> fenetre grand grande par rapport au foramt de l'ecran
// 8 -> map non entouree de mur
// 9 -> manque le player (P)
// 10 -> manque la sortie (E)
// 11 -> manque un collectible (C) 
// 12 -> autre caractere que les caracteres autorises

int	ft_map_parsing_manag(char *file, t_game *game)
{
	int		code_error;

	ft_make_tab_map(file, game);
	code_error = 0;
	if (ft_rectangular(game) != 0)
		code_error = 6;
	else if (ft_out_of_screen_format(game) != 0)
		code_error = 7;
	else if (ft_surrounded_by_walls(game) != 0)
		code_error = 8;
	else if (ft_player_exists(game) != 0)
		code_error = 9;
	else if (ft_exit_exists(game) != 0)
		code_error = 10;
	else if (ft_collectible_exists(game) != 0)
		code_error = 11;
	else if (ft_other_elem(game) != 0)
		code_error = 12;
	if (code_error != 0)
		return (ft_error_messages_file_and_map(code_error));
	return (1);
}
