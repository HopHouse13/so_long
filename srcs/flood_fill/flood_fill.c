/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:32:10 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/30 16:58:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui controle si un chemin valide existe entre la position initiale
// du player et l'exit en passant par tous les collectibles.
// 
// -----------------------------------------------------------------------------
// 
// Cette fonction est recursive.(Elle s'appelle elle meme selon des conditions)
// Son principe est de parcourir l'ensemble des cases accessibles en partant de
// la position initiale du player.
// 1] A chaque appel de celle-ci, 3 "if" check differentes choses:
// - Si les compteurs de collectibles et exit sont a zero. si c'est le cas cela
// signifit qu'il ya un chemin possible pour finir la map(no need de poursuivre)
// - Si la case actuelle a "C" comme caractere. si oui -> collectible_counter--.
// - Si la case actuelle a "E" comme caractere. si oui -> exit_counter--.
// 2] Puis la case actuelle devient prend comme caractere -> "1" pour que les
// appels futurs ne puissent pas acceder a cette case car deja check.
// 3] enfin une serie de 4 "if" qui gere si la case ou la fonction veut se
// deplacer est autre chose qu'un mur (1).
// si c'est le cas, la fonction ft_flood_fill est de nouveau appelee et
// recommence tout le processus jusqu'a que les conditions des 4 "if" soient
// fausses.
// Les 4 "if" representent les 4 directions possible: Haut, bas, gauche, droite.

int	ft_flood_fill(t_game *game, t_map *map_ff, int line, int col)
{
	if (map_ff->collectible_counter == 0 && map_ff->exit_counter == 0)
		return (0);
	if (map_ff->tab_map[line][col] == 'C')
		map_ff->collectible_counter--;
	if (map_ff->tab_map[line][col] == 'E')
		map_ff->exit_counter--;
	map_ff->tab_map[line][col] = '1';
	if (map_ff->tab_map[line + 1][col] != '1')
		ft_flood_fill(game, map_ff, line + 1, col);
	if (map_ff->tab_map[line - 1][col] != '1')
		ft_flood_fill(game, map_ff, line - 1, col);
	if (map_ff->tab_map[line][col + 1] != '1')
		ft_flood_fill(game, map_ff, line, col + 1);
	if (map_ff->tab_map[line][col - 1] != '1')
		ft_flood_fill(game, map_ff, line, col - 1);
	return (0);
}

// _____________________________________________________________________________
// 
// Fonction qui initialise la strucutre map_ff.
// 
// -----------------------------------------------------------------------------
// 
// L'initialisation est complete a partir de la structure game->map 
// (precedemment complete) sauf pour le double tableau qui est initialise avec
// ft_make_ff_map.

void	ft_initialisation_struct_ff(t_game *game, t_map *map_ff)
{
	map_ff->tab_map = ft_make_ff_map(game);
	map_ff->col_map = game->map.col_map;
	map_ff->line_map = game->map.line_map;
	map_ff->exit_counter = game->map.exit_counter;
	map_ff->collectible_counter = game->map.collectible_counter;
}

// _____________________________________________________________________________
// 
// Fonction qui initialise le double tableau de la map.
// 
// -----------------------------------------------------------------------------
// 
// Le malloc de la premiere couche est initialise avec le nb de ligne stocke
// dans line_map.
// Boucle : tant que le nombre de boucle n'a pas atteint le nombre de ligne
// ca continue.
// A chaque iteration l'enssemble de la ligne indexe 'i' de map.tab_map est 
// dupliquee et stocker dans la ligne indexe "i" de ff_map via ft_strdup.
// Apres avec parcouru tout la premiere couche du tableau, le dernier pointeur
// prend comme valeur NULL pour signaliser la fin de la chaine de pointeur.
// Le double tableau fini, la fonction le renvoie pour l'initialisation de
// -> map_ff->tab_map

char	**ft_make_ff_map(t_game *game)
{
	long int	i;
	char		**ff_map;

	ff_map = malloc((game->map.line_map + 1) * sizeof(char *));
	if (!ff_map)
		return (NULL);
	i = -1;
	while (++i < game->map.line_map)
		ff_map[i] = ft_strdup(game->map.tab_map[i]);
	ff_map[i] = NULL;
	return (ff_map);
}

// _____________________________________________________________________________
// 
// Fonction qui libere l'espace memoire du double tableau de la structure map_ff
// 
// -----------------------------------------------------------------------------
// 
// Classique, si le le pointeur du double tableau existe alors la boucle pour
// parcourir l'ensemble de la premiere dimension du tableau demarre. A chaque
// iteration de la boucle, l'espace du le pointeur du tableau de la deuxieme
// dimension est libere.
// A la fin de la boucle, la memoire du tableau de la premiere dimension qui
// contenait les pointeurs des tableau de la deuxieme dimension est liberee.

void	ft_free_ff_map(t_map *ff_map)
{
	int	i;

	i = -1;
	if (ff_map->tab_map)
	{
		while (ff_map->tab_map[++i])
			free(ff_map->tab_map[i]);
		free(ff_map->tab_map);
	}
}
