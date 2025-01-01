/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:25:11 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/01 17:35:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// La fonction initialise les elements graphiques necessaires pour demarrer le
// jeu. Elle s'occupe de creer la fenetre, d'initialiser les images, de gerer 
// les entrees utilisateur (clavier, fermeture de fenetre), et de demarrer la
// boucle d'evenements.
// 
// -----------------------------------------------------------------------------
// 
// 1] Initialisation de la connection entre la Minilibx et le programme avec la
// fonction mlx_init(). Elle renvoit un pointeur vers une structure necessaire
// pour le bon fonctionnement de la plupart des fonctions de la minilibx.
// Ce pointeur est stocke dans mlx_ptr.
//
// 2] Initialisation de la fenetre de jeu aux bonnes dimensions. Les dimensions
// sont calculees en fonction du nombre d'elements de la map * la taille d'un
// element. Tous les elements font la meme taille. (64x64 pixels)
// La fonction qui gere la fenetre de jeu est mlx_new_window. Elle prend comme
// parametres -> le pointeur mlx_ptr (connection avec la mlx), la taille de la
// largeur et de la hauteur (en pixel) et le titre de la fenetre.
// Cette fonction renvoie un pointeur que sera stocke dans win_ptr.
//
// 3] ft_initialisation_img serre a l'initialisation des images de chaque 
// element. Elle retourne (1) si elle na bien initialisee toutes les images,
// dans le cas contraire, elle renvoie (0). Elle prend comme parametre d'entree
// la structure game. (struct initilisee en debut de programme dans le main)
//
// 4] La fonction mlx_loop_hook est une fonction de la mlx qui a plusieurs
// utilites. Son utilitee pour so_long est le rafraichissement de l'affichage.
// Elle prend comme parametre mlx_ptr(connection avec la mlx), la fonction
// appelee lorsque elle meme sera appelee (cette fonction est transnise en
// referencement), et la struct game, parametre d'entree pour la fonction
// ft_refresh_display.
// Cette fonction est appelee a chaque frame avec l'appel de ft_refresh_display.
//
// 5] la fonction mlx_hook (fonction de la mlx) est une fonction d'ecoute.
// Lorsqu'une boucle d'evenement est demarree, mlx_hook est a l'ecoute d'un type
// d'evenement bien precis.
// Elle prend 5 parametres d'entrees:
// - Le pointeur de la fenetre initialiseeplus haut avec son pointeur (win_ptr).
// ce pointeur lui permet de savoir quelle fenetre il faut surveiller.
// - La constante en int (defini par le header X11/X.h) qui est un identifiant
// d'un type precis d'evenement specifique que l'on veut capter.
// Ici c'est "KeyPress" -> appui sur une touche du clavier.
// - La constante (int) qui definit un mask d'evenement. Dans la fonction, c'est
// pour indiquer au programme de surveiller les evenements de type "KeyPress".
// Avec ces deux constantes, le programme sait que quand un bouton est presse
// sur le clavier, il faut lancer l'appel de la fonction defini dans cette
// fonction mlx_hook.
// - La fonction ft_input_management transmise en referencement. Cette fonction
// sera appelee a chaque fois que cette mlx_hook sera apellee.
// - Enfin la struct game pour les parametres d'entrees de la fonction appelee.
// (ft_input_management)
// Au finale, cette fonction mlx_hook va ecouter et appelee la fonction
// ft_input_management lorsque un bouton du clavier sera presse.
// 
// 6] Encore une nouvelle fonction mlx_hook (fonction d'ecoute lors d'une boucle
// d'evenement est demarree), meme principe mais cette fois-ci c'est pour gerer
// la fermeture de la fenetre avec la croix en haut.
// Les deux constances:
// - DestroyNotify -> constante qui represente un type d'evenement bien precis.
// La, c'est l'evenement "clic sur la croixsur de la fenetre".
// - StructureNotifyMask -> masque d'evenement.. J'avoue ne pas comprendre
// le foncitonnement exacte. Je sais juste que c'est pour surveiller un
// changement dans la structure de la fenetre surveillee.
// Le reste ne change pas ( a part la fonction qui n'est pas la meme).
//
// 7] Enfin mlx_loop avec le pointeur qui fait la connection avec la mlx. Cette
// fonction demarre une boucle d'evenement. tant que le programme est en cours
// d'execution, cette boucle reste active. Ca permet la gestion a la minilibx
// de gerer les differents type d'evenements comme clic de soucis et bouton de
// clavier presse ou encore le rafraichissement de l'affichage.
// 
// 8] return (1) si tout s'est deroule comme il le faut.

int	ft_game_start_management(t_game *game)
{
	game->graph.mlx_ptr = mlx_init();
	if (!game->graph.mlx_ptr)
		return (0);
	game->graph.win_ptr = mlx_new_window(game->graph.mlx_ptr,
			game->map.col_map * ELEM_SIZE,
			game->map.line_map * ELEM_SIZE,
			"Petit cercle deviendra carre");
	if (!game->graph.win_ptr)
		return (0);
	if (!ft_initialisation_img(game) || !ft_initialisation_img_1(game))
		return (0);
	mlx_loop_hook(game->graph.mlx_ptr, &ft_refresh_display, game);
	mlx_hook(game->graph.win_ptr, KeyPress, KeyPressMask, &ft_input_management,
		game);
	mlx_hook(game->graph.win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_cross_management, game);
	mlx_loop(game->graph.mlx_ptr);
	return (1);
}
