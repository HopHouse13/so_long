/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/30 18:25:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction principale qui a pour role d'appeler les pricipales fonction du
// programme so_long.
// 
// -----------------------------------------------------------------------------
// 
// 1] Si les parametres d'entree sont au nombre de 2. Sinon message d'erreur.
// 2] Appel de la fonction ft_initialisation_structs pour l'initialisation de 
// l'ensemble des valeurs de la tructure game, initilisee au debut.
// 3] "if" avec l'appel de $ fonctions differentes (l'odre est important)
// - ft_file_parsing_manag : controle le fichier en soit (si il existe, si
//  il a la bonne extention, si c'est bien un fichier, etc)
// - ft_map_parsing_manag : controle de la validite de la map. (si elle est 
// restangulaire, au bon format, entouree de mur, si tous les elements qui doit
// la composer est present, etc)
// - ft_flood_fill_manag : verification si un chemin est possible entre la
// position initiale du player et l'exit en passant par tous les collectibles.
// - ft_game_start_management : enfin le jeu peux commencer. Cette fonction
// a pour mission, la gestion du la partie graphique.
// 4] A avant la fin du programme la fonction ft_free est appelee pour liberer
// toutes les zones de memoires allouees dynamiquement dans la memoire vive.

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		ft_initialisation_structs(&game);
		if (ft_file_parsing_manag(av[1])
			&& ft_map_parsing_manag(av[1], &game)
			&& ft_flood_fill_manag(&game)
			&& ft_game_start_management(&game))
		{
			ft_free(&game);
			return (0);
		}
		ft_free(&game);
		return (1);
	}
	else
	{
		write(2, RED"Error\nNombre d'arguments incorrect.\n"RESET, 41);
		return (1);
	}
}
