/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:51 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/26 18:43:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* 	1 -> l'argument est une repertoire
 	2 -> fichier inexistant
	3 -> maivaise extention
	4 -> inouvrable (droits)
	5 -> fichier vide

	
	6 -> map non carre
	7 -> map non entouree de mur
	8 -> manque le player (P)
	9 -> manque la sortie (E)
	10 -> manque un item (C) */

int	ft_file_parsing_management(char *name_map)
{
	if (ft_is_not_a_directory(name_map) != 0)
		return (1);
	else if (ft_existing_file(name_map) != 0)
		return (2);
	else if (ft_valid_extension(name_map) != 0)
		return (3);
/* 	else if (ft_file_not_openable(name_map) != 0)
		return (ft_file_not_openable(name_map)); */
	else if (ft_empty_file(name_map) != 0)
		return (5);
	return (0);
}
