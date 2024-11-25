/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:51 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/25 18:52:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
/* 	 
	1 -> l'argument est une repertoire
	2 -> maivaise extention
	3 -> fichier inexistant
	4 -> inouvrable (droits)
	5 -> fichier vide
	0 -> fichier valide */

int	ft_file_parsing_management(char *name_map)
{
	if (ft_is_not_a_directory(name_map) != 0)
		return (ft_is_not_a_directory(name_map));
	// else if (ft_valid_extension(name_map) != 0)
	// 	return (ft_valid_extension(name_map));
	// else if (ft_existing_file(name_map) != 0)
	// 	return (ft_existing_file(name_map));
	// else if (ft_file_not_openable(name_map) != 0)
	// 	return (ft_file_not_openable(name_map));
	// else if (ft_empty_file(name_map) != 0)
	// 	return (ft_empty_file(name_map));
	return (0);
}
