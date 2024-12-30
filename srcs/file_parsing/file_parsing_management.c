/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:51 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/30 18:32:15 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui coordonne les differents controles du fichier.
// 
// -----------------------------------------------------------------------------
// 
// 1 -> l'argument est une repertoire
// 2 -> fichier inexistant
// 3 -> maivaise extention
// 4 -> inouvrable (droits)
// 5 -> fichier vide

int	ft_file_parsing_manag(char *file)
{
	int	code_error;

	code_error = 0;
	if (ft_is_not_a_directory(file) != 0)
		code_error = 1;
	else if (ft_existing_file(file) != 0)
		code_error = 2;
	else if (ft_valid_extension(file) != 0)
		code_error = 3;
	else if (ft_file_not_openable(file) != 0)
		code_error = 4;
	else if (ft_empty_file(file) != 0)
		code_error = 5;
	if (code_error != 0)
		return (ft_error_messages_file_and_map(code_error));
	return (1);
}
