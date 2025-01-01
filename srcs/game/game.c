/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:02 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/01 20:27:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui initialise les images au format xpm en element exploitable par
// la mlx.
// 
// -----------------------------------------------------------------------------
// 
// La fonction mlx_xpm_file_to_image prend 4 parametres d'entres.
// - Le pointeur de la mlx (connection avec la mlx)
// - Une chaine de caractere brute qui est le chemin du fichier(.xpm) du visuel.
// - Un int qui represente l'abscisse de l'element. Ce int est transmis en
// referencement.
// - Un autre int qui represente l'ordonnee de l'element. Ce int est transmis
//   egalement en referencement.
//
// Cette fonction renvoie un pointeur qui sera utilise pour afficher l'element
// vers le quel il pointe.
//
// Controle si il a bien ete initialise, si c'est le cas -> return (1) sinon (0)
//
// Chaque image une variable de struct "img" est mise en place. Dedans il y a
// les coordonnees et le pointeur de l'element.

int	ft_initialisation_img(t_game *game)
{
	game->graph.wall.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/wall.xpm", &game->graph.wall.l, &game->graph.wall.h);
	if (!game->graph.wall.img)
		return (0);
	game->graph.floor.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/floor.xpm", &game->graph.floor.l, &game->graph.floor.h);
	if (!game->graph.floor.img)
		return (0);
	game->graph.c.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/c.xpm", &game->graph.c.l, &game->graph.c.h);
	if (!game->graph.c.img)
		return (0);
	game->graph.e_close.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/e_close.xpm", &game->graph.e_close.l,
			&game->graph.e_close.h);
	if (!game->graph.e_close.img)
		return (0);
	game->player.p_loose.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/p_loose.xpm", &game->player.p_loose.l,
			&game->player.p_loose.h);
	if (!game->player.p_loose.img)
		return (0);
	return (1);
}

// _____________________________________________________________________________
// 
// Deuxieme fonction qui initialise les images au format xpm en element
// exploitable par la mlx.
// 
// -----------------------------------------------------------------------------
// 
// Meme principe que la fonction precedente.
// Fonction mise en place pour respecter la regle des 25 lignes/fonction de la 
// norminette.

int	ft_initialisation_img_1(t_game *game)
{
	game->player.p_win.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/p_win.xpm", &game->player.p_win.l,
			&game->player.p_win.h);
	if (!game->player.p_win.img)
		return (0);
	game->graph.e_open.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/e_open.xpm", &game->graph.e_open.l,
			&game->graph.e_open.h);
	if (!game->graph.e_open.img)
		return (0);
	game->player.p_and_e.img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			"./sprites/p_and_e.xpm", &game->player.p_and_e.l,
			&game->player.p_and_e.h);
	if (!game->graph.e_open.img)
		return (0);
	return (1);
}
// _____________________________________________________________________________
// 
// Fonction qui gere l'affichage de la totalite des elements de la map dans la
// fenetre et quand faut-il actualiser l'affichage.
// 
// -----------------------------------------------------------------------------
// 
// Cette fonction est appelee a chaque appel de loop_hook. Cela veut dire a
// chaque frame.
// Pour eviter le refrech inutile, la fonction ft_refresh_display s'active
// uniquement quand il y a un element qui a bouge dans le jeu. Cette condition
// est traduit en deux condition :
//
// - que le pointeur de la window soit existant.(que la fenetre soit la)
// - que le flag flag_refresh a pour valeur 0.
//
// Dans ce cas, la fonction va parcourir le double tableau map et afficher
// l'enssemble des elements de la map et le player.
// Pour chaque coordonnee, deux fonctions peut etre appelees. Si les coordonnees
// de la case sont les meme que celle du player -> ft_display.
// sinon (pourtout le reste) -> ft_display_elem.
//
// Apres avoir affiche la totalite des elements, la fonction passe flag_refresh
// a 1. Cela evite les refresh inutiles.

int	ft_refresh_display(t_game *game)
{
	long int	x;
	long int	y;

	x = 0;
	y = 0;
	if (game->graph.win_ptr && game->graph.flag_refresh == 0)
	{
		while (y < game->map.line_map)
		{
			x = 0;
			while (x < game->map.col_map)
			{
				if (game->player.y == y && game->player.x == x)
					ft_display(game);
				else
					ft_display_elem(game, x, y);
				x++;
			}
			y++;
		}
		game->graph.flag_refresh = 1;
	}
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui gere l'affichage de l'element player et dans quel etat.
// 
// -----------------------------------------------------------------------------
// 
// La fonction utilise les coordonnees stockees dans la struct "player".(x et y)
// pour player aux bonnes coordonnes le player dans la fenetre.
// Ces coordonnees sont mises a jour lors du mouvement du player dans une autre
// fonction.
//
// Pour afficher un element dans la fenetre, la fonction mlx_put_image_to_window
// est utilisee.
// Elle prend 5 parametres:
//
// - Le pointeur mlx_ptr (connection avecl a mlx)
// - Le pointeur win_ptr (pointeur de la fenetre)
// - Le pointeur de l'element (initialise en amont)
// - L'abscisse de l'element qui va etre affiche (x)
// - L'ordonnee de l'element qui va etre affiche (y)
//
// Tous ces variables sont stocker dans la struct "player", elle meme stocker
// dans la struct "game".
// 
// Le player peut etre dans 3 etat differents :
//
// - 1er if -> Il peut se situer sur l'exit (E) mais ne pas avoir recupere tous
// les collectibles -> visuel du player sur l'exit.
// - 2eme else if -> il peux avoir recupere tous les collectibles -> player est
// un carre heureux.
// - 3eme else -> dans tous les autres cas -> player est cercle triste.
//
// POur chaque condition, le controle que le pointeur d'element soit bien
// initialise.
// Les coordonnees sont multipliees par ELEM_SIZE qui est une constant defini
// dans le header. Cette constante int represnetant la taille en pixel de 
// chaque element. Tous les elements ont la meme taille. (64x64)

// Contrairement aux autres coordonnees des elements qui sont dirrectement
// transmit par la fonction mere (ft_refresh_display) avec le defilement dans
// le double tableau map_tab.

void	ft_display(t_game *game)
{
	if (game->map.tab_map[game->player.y][game->player.x] == 'E'
		&& game->map.collectible_counter != 0 && game->player.p_and_e.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->player.p_and_e.img, game->player.x * ELEM_SIZE,
			game->player.y * ELEM_SIZE);
	else if (game->map.collectible_counter == 0 && game->player.p_win.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->player.p_win.img, game->player.x * ELEM_SIZE,
			game->player.y * ELEM_SIZE);
	else if (game->player.p_loose.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->player.p_loose.img, game->player.x * ELEM_SIZE,
			game->player.y * ELEM_SIZE);
}

// _____________________________________________________________________________
// 
// Fonction qui gere l'affichage de tous les elements de la map et dans quel 
// etat.
// 
// -----------------------------------------------------------------------------
// 
// C'est exatement le meme principe que la fonction ft_display.
// Sauf que les coordonnees des elements sont dirrectement transmises par la
// fonction mere avec le le parcourt du double tableau et les x et y.
// Chaaue appel de ft_display_elem est pour une cooredonnee bien precise.
// Une seule conditions sera valide.
// 
// 2 subtilitees sont presentes :
//
// - Il y a deux visuels de l'exit (E)
//   -> si les collectibles ne sont pas tous ramasses -> exit fermee.
//   -> si les collectibles sont tous ramasses -> exit ouverte.
//
// - le dernier else if est utilse qu'une seule fois. Elle serre a placer un
// "floor" a la place de la position de depart du player. Car le player n'est
// pas gere dans cette fonction.

void	ft_display_elem(t_game *game, long int x, long int y)
{
	if ((game->map.tab_map)[y][x] == '1' && game->graph.wall.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->graph.wall.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == '0' && game->graph.floor.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->graph.floor.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == 'C' && game->graph.c.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->graph.c.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == 'E'
			&& game->map.collectible_counter != 0 && game->graph.e_close.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->graph.e_close.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == 'E'
			&& game->map.collectible_counter == 0 && game->graph.e_open.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->graph.e_open.img, x * ELEM_SIZE, y * ELEM_SIZE);
	else if (game->map.tab_map[y][x] == 'P' && game->graph.floor.img)
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr,
			game->graph.floor.img, x * ELEM_SIZE, y * ELEM_SIZE);
}
