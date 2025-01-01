/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:13:57 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/01 20:27:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui controle si la map est rectangulaire.
// 
// -----------------------------------------------------------------------------
// 
// Principe : controle si chaque ligne de la map a le meme nombre de caracteres.
// 1] nb_of_col prend le nombre de caractere
// 2] boucle : tant que la premiere couche du tableau n'est pas terminee -> i++.
// si la valeur de nb_of_col est difference de la taille de la ligne actuelle,
// -> resturn (1)
// 3] L38 et L39 -> inialisation du format de la map de la structure "map"

int	ft_rectangular(t_game *game)
{
	long int	i;
	int			nb_of_col;

	nb_of_col = ft_strlen(game->map.tab_map[0]);
	i = -1;
	while (game->map.tab_map[++i])
		if (nb_of_col != ft_strlen(game->map.tab_map[i]))
			return (1);
	game->map.col_map = ft_strlen(game->map.tab_map[0]);
	game->map.line_map = i;
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui controle si le format de la fenetre de jeu ne soit plus grand
// que le format de l'ecran.
// 
// -----------------------------------------------------------------------------
// 
// Principe : compare le nombre de pixels que fera la fenetre et le nombre de 
// pixel du format de l'ecran sur la longueur et la hauteur.
// Pour avoir le nombre de pixels de loa longueur et la largeur, la fonction
// multiplie le nombre d'element et la taille de chaque element.
// L'emsemble des elements font 64x64 pixels.

int	ft_out_of_screen_format(t_game *game)
{
	if (game->map.col_map * ELEM_SIZE > SCREEN_LENGHT
		|| game->map.line_map * ELEM_SIZE > SCREEN_WILTH)
		return (1);
	return (0);
}

// _____________________________________________________________________________
// 
// Fonction qui controle si la map est bien entouree de mur (1).
// 
// -----------------------------------------------------------------------------
// 
// 2 boucles
//
// Boucle 1 : check si c'est bien uniquement des 1 sur la premiere et
// la derniere ligne.
// L90 -1 car on passe du nombre de ligne a l'indexe (1eme ligne -> indexe 0)
// Boucle 2 : check si le premier et le dernier caractere de chaque ligne
// intermediaire soient bien uniquement le caractere 1.
// L93 pas la peine de controler la premiere ligne -> i va commencer a "1".
// (2eme ligne) au premiere appel de la boucle.
// L94 "-1" evite de check la derniere ligne inutilement (deja check).
// L96 le dernier caractere est au niveau de d'indexe -> (nb de caractere - 1)
// donc -1.

int	ft_surrounded_by_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.col_map)
	{
		if (game->map.tab_map[0][i] != '1' ||
			game->map.tab_map[game->map.line_map - 1][i] != '1')
			return (1);
	}
	i = 0;
	while (++i < game->map.line_map - 1)
		if (game->map.tab_map[i][0] != '1' ||
			game->map.tab_map[i][game->map.col_map - 1] != '1')
			return (1);
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui controle si il y a uniquement 1 player sur la map.
// 
// -----------------------------------------------------------------------------
// 
// Double boucle pour parcourir le double tableau.
// Si le caractere est egale a "P" -> nb_of_player++ et save les coordonnees du
// player.
// si nb_of_player est different de 1 -> return (1)

int	ft_player_exists(t_game *game)
{
	int	i;
	int	j;
	int	nb_of_player;

	nb_of_player = 0;
	i = 0;
	while (game->map.tab_map[i])
	{
		j = 0;
		while (game->map.tab_map[i][j])
		{
			if (game->map.tab_map[i][j] == 'P')
			{
				nb_of_player++;
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		i++;
	}
	if (nb_of_player != 1)
		return (1);
	return (0);
}
// _____________________________________________________________________________
// 
// Fonction qui controle si il y a uniquement 1 exit sur la map.
// 
// -----------------------------------------------------------------------------
// 
// Double boucle pour parcourir le double tableau.
// Si le caractere est egale a "E" -> nb_of_exit++ et save le nombre d'exit.
// Si nb_of_exit est different de 1 -> return (1)

int	ft_exit_exists(t_game *game)
{
	int	i;
	int	j;
	int	nb_of_exit;

	nb_of_exit = 0;
	i = 0;
	while (game->map.tab_map[i])
	{
		j = 0;
		while (game->map.tab_map[i][j])
		{
			if (game->map.tab_map[i][j] == 'E')
			{
				nb_of_exit++;
				game->map.exit_counter++;
			}
			j++;
		}
		i++;
	}
	if (nb_of_exit != 1)
		return (1);
	return (0);
}
