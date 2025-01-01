/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:26:52 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/01 20:31:57 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui verifie si le pointeur de la window est bien initilise et fais
// la distinction si la touche ESC ou bien une autre touche a ete pressee.
// En fonction de la touche pressee, la fonction appele soit mlx_loop_end (pour
// clore la bouple d'evenement), soit ft_movement_management (pour gerer le
// deplacement du player)
//
// -----------------------------------------------------------------------------
// 
// Tout est dit dans la description de la fonction.
// l'int keysym est transmis par la mlx. Elle represente un code unique qui
// correspond a une touche du clavier bien specifique.
// C'est constances sont definis dans la bibliotheque <X11/keysym.h>
// avec un nom et un code d'identification
// 
// ex:
// XK_w -> touche du w
// code d'identificaion -> 119
//
// Avec ca, nous pouvons identifier la touche pressee.

int	ft_input_management(int keysym, t_game *game)
{
	if (game->graph.win_ptr)
	{
		if (keysym == XK_Escape)
			mlx_loop_end(game->graph.mlx_ptr);
		else
			ft_movement_management(keysym, game);
	}
	return (0);
}
// _____________________________________________________________________________
// 
// La fonction identifie la touche pressee, le mouvement demande. Si c'est
// possible, elle modifie les coordonnees du player, appelle 
// ft_collectibles_and_exit_management pour une eventuel changement d'etat d'un
// element de la map. Enfin elle change l'etat du flag pour declancher un
// rafraichessement de l'affichage.
//
// -----------------------------------------------------------------------------
//
// La fonction identifie la touche pressee pour savoir quel mouvement est
// demande de faire au player. Elle verifie si le mouvement est possible dans la
// map avec le retour de la fonction ft_movement_possible.
// Le 1er parametre de cette fonction represente le mouvement demande.
// Si le retour est ok pour le mouvement, la fonction modifie les coordonnees du
// player dans la structure "player".
// La fonction ft_collectibles_and_exit_management est appelee pour controler si
// un changement visuel pour les collectibles ou si le player a recolte
// l'ensemble des collectibles et qu'il se trouve sur l'exit.
// Enfin comme il y eu une touche pressee, la variable change d'etat de 1 a 0
// pour mlx_loop_hook actualise l'affichage.

int	ft_movement_management(int keysym, t_game *game)
{
	if ((keysym == XK_w || keysym == XK_Up)
		&& (ft_movement_possible('^', game)))
		game->player.y -= 1;
	else if ((keysym == XK_s || keysym == XK_Down)
		&& (ft_movement_possible('v', game)))
		game->player.y += 1;
	else if ((keysym == XK_a || keysym == XK_Left)
		&& (ft_movement_possible('<', game)))
		game->player.x -= 1;
	else if ((keysym == XK_d || keysym == XK_Right)
		&& (ft_movement_possible('>', game)))
		game->player.x += 1;
	ft_collectibles_and_exit_management(game);
	game->graph.flag_refresh = 0;
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui controle si le mouvement demande au player soit possible.
// Si c'est le cas, elle renvoit le retour de la valeur de la fonction :
// ft_print_movement_nb ou 0 si le mouvement demande n'est pas possible.
//
// -----------------------------------------------------------------------------
//
// Chacun des 4 if est dedie a une  des 4 directions possible. La directrion est
// identifiee par le caractere en parametre d'entree "directrion". (caractere 
// selectionne en fonction de la touche pressee)
// Pour chaque if, la fonction verifie si la future coordonnee n'est pas un "1"
// (mur) et qu'elle ne sort pas en dehors des coordonnees de la map.
// Cela evite aussi les seg. fault.
// enfin elle renvoit le retour de la fonction ft_print_movement_nb.
// 1 -> mouvement confirme
// 0 -> mouvement impossible

int	ft_movement_possible(char direction, t_game *game)
{
	if (direction == '^'
		&& game->map.tab_map[game->player.y - 1][game->player.x] != '1'
		&& game->player.y - 1 >= 0)
		return (ft_print_movement_nb(game));
	else if (direction == 'v'
		&& game->map.tab_map[game->player.y + 1][game->player.x] != '1'
		&& game->player.y + 1 < game->map.line_map)
		return (ft_print_movement_nb(game));
	else if (direction == '<'
		&& game->map.tab_map[game->player.y][game->player.x - 1] != '1'
		&& game->player.x - 1 >= 0)
		return (ft_print_movement_nb(game));
	else if (direction == '>'
		&& game->map.tab_map[game->player.y][game->player.x + 1] != '1'
		&& game->player.x + 1 < game->map.col_map)
		return (ft_print_movement_nb(game));
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui gere l'affichage des numeros de mouvement sur le terminal.
//
// -----------------------------------------------------------------------------
//
// Elle incremente la variable movements qui se trouve dans la struct "player".
// Elle a ete initialisee au prealable a 0. A chaque appelle, elle sera
// incrementee de 1 et sa valeur sera conservee tout au long du programme car
// c'est une variable persistante car stockee dans la grande struct "game"
// initialisee au tout debut du programme (main) et sera persistante jusqu'a la
// fin du programme. "game" est transmise en referencement dans toutes les
// fonctions qui ont besoin d'information stockee dedans.
// 
// A chaque appel, un write affiche "Move N. " et ft_putnbr_and_return_to_line
// est appelee.
//
// Cette fonction serre a afficher "movements" et un saut de ligne.
//
// Enfin elle renvoit (1). Un 1 important car il sera transmit jusqu'a
// ft_movement_management et qui derterminera si oui ou non le mouvement est
// confirme ou pas.

int	ft_print_movement_nb(t_game *game)
{
	game->player.movements++;
	write (1, "Move N. ", 8);
	ft_putnbr_and_return_to_line(game->player.movements);
	return (1);
}
// _____________________________________________________________________________
// 
// Fonction qui gere a comptabiliser les collectibles, a faire disparaitre les
// collectibles prient et a clore la boucle d'evenement quand le jeu est fini.
//
// -----------------------------------------------------------------------------
//
// Fonction simple.
// 1er if -> si le player est sur une case "C" (collectible) alors la case
// devient "0" (Floor) et decrementation de 1 le compteur des collectibles.
//
// 2eme if -> si le player est sur la case "E" (exit) et que le compteur de
// collectibles est egale a 0 alors appel de mlx_loop_end pour stopper la boucle
// d'evenement.

void	ft_collectibles_and_exit_management(t_game *game)
{
	if (game->map.tab_map[game->player.y][game->player.x] == 'C')
	{
		game->map.tab_map[game->player.y][game->player.x] = '0';
		game->map.collectible_counter--;
	}
	else if (game->map.tab_map[game->player.y][game->player.x] == 'E'
			&& game->map.collectible_counter == 0)
		mlx_loop_end(game->graph.mlx_ptr);
}
