/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:02:13 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/24 13:26:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui gene l'affichage sur le terminal des messages d'erreurs en 
// fonction du code_erreur transmit.
// 
// -----------------------------------------------------------------------------
// 
// 1	-> l'argument est une repertoire
// 2	-> fichier inexistant
// 3	-> maivaise extention
// 4	-> inouvrable (droits)
// 5	-> fichier vide

// 6	-> map non carre
// 7	-> map hors ecran
// 8	-> map non entouree de mur
// 9	-> manque le player (P)
// 10	-> manque la sortie (E)
// 11	-> manque un collectible (C)
// 12	-> element non autorise

// 1	-> collectibles non accessibles
// 2	-> exit non accessible

int	ft_error_messages_file_and_map(int code_error)
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
		write(2, RED"Error\nLa map est plus grande que l'ecran.\n"RESET, 52);
	else if (code_error == 8)
		write(2, RED"Error\nMap non encadrée par des murs.\n"RESET, 47);
	else if (code_error == 9)
		write(2, RED"Error\nNombre de joueur non valide.\n"RESET, 45);
	else if (code_error == 10)
		write(2, RED"Error\nNombre de sortie non valide.\n"RESET, 45);
	else if (code_error == 11)
		write(2, RED"Error\nAvec des collectables, c'est plus fun.\n"RESET, 55);
	else if (code_error == 12)
		write(2, RED"Error\nÉlément non autorisé.\n"RESET, 40);
	return (0);
}

void	ft_error_messages_ff(int code_error)
{
	if (code_error == 1)
		write(2, RED"Error\nCollectible non accessible.\n"RESET, 44);
	else if (code_error == 2)
		write(2, RED"Error\nExit non accessible.\n"RESET, 37);
}
