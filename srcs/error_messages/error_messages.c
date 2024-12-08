/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:02:13 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 00:26:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

	// 1 -> l'argument est une repertoire
	// 2 -> fichier inexistant
	// 3 -> maivaise extention
	// 4 -> inouvrable (droits)
	// 5 -> fichier vide

	// 6 -> map non carre
	// 7 -> map non entouree de mur
	// 8 -> manque le player (P)
	// 9 -> manque la sortie (E)
	// 10 -> manque un collectible (C)

	// 11 -> collectibles non accessibles
	// 12 -> exit non accessible

void	ft_error_messages_manag(int code_error)
{
	if (code_error == 1)
		write(2, RED"Error\nL'argument d'entrée est un repertoire.\n"RESET, 55);
	else if (code_error == 2)
		write(2, RED"Error\nFichier inexistant.\n"RESET, 36);
	else if (code_error == 3)
		write(2, RED"Error\nExtention du fichier non valide.\n"RESET, 49);
	else if (code_error == 4)
		write(2, RED"Error\nFichier non ouvrable.\n"RESET, 38);
	else if (code_error == 5)
		write(2, RED"Error\nFichier vide.\n"RESET, 30);
	else if (code_error == 6)
		write(2, RED"Error\nMap non rectangulaire.\n"RESET, 39);
	else if (code_error == 7)
		write(2, RED"Error\nMap non encadrée par des murs.\n"RESET, 47);
	else if (code_error == 8)
		write(2, RED"Error\nNombre de joueur non valide.\n"RESET, 45);
	else if (code_error == 9)
		write(2, RED"Error\nNombre de sortie non valide.\n"RESET, 45);
	else if (code_error == 10)
		write(2, RED"Error\nAvec des collectables, c'est plus fun.\n"RESET, 55);
	else if (code_error == 11)
		write(2, RED"Error\nCollectible non accessible.\n"RESET, 44);
	else if (code_error == 12)
		write(2, RED"Error\nExit non accessible.\n"RESET, 37);
}
