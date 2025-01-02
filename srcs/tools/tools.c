/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:53:58 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/02 14:38:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"
// _____________________________________________________________________________
// 
// Fonction qui compte le nombre de caractere dans une chaine de caracteres.
// 
// -----------------------------------------------------------------------------
// 
// Tout est dit dans la description.

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
// _____________________________________________________________________________
// 
// Fonction utilisee pour le GNL, elle alloue dynamiquement une zone memoire
// correspondant a la taille et ou type transmis en parametre. Elle remplit
// chaque cellule de memoire allouee par '\0' caractere de fin de chaine.
// 
// -----------------------------------------------------------------------------
// 
// Controle si la taille et le type est egale ou suprieur a 1 sinon -> malloc(0)
// Controle si pas d'overflow.
// controle si le malloc a bien fonctionne.
// boucle pour remplir la zone de memoire par des '\0'
// return un ptr qui pointe vers le debut de cette zone memoire.

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	int				i;

	if (count < 1 || size < 1)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (count > 0)
	{
		ptr[i] = '\0';
		i++;
		count--;
	}
	return (ptr);
}
// _____________________________________________________________________________
// 
// Fonction qui recherche la 1eme occurence dans la chaine de carac.
// 
// -----------------------------------------------------------------------------
// 
// boucle : tant que str existe et qu'aucune occurrence est trouvee > i++
// si occurrence trouvee -> sortie de la boucle -> if (securite occurrence)
// -> return le  pointeur de l'occurrence (en hexadécimal)
// si pas d'occurence, return NULL
// "int c" est cast en (char) -> comparaison entre les (char *) et le char c
// le return est cast en (char *) > const char en parametre et en sortie char
// cast = transtypage

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
// _____________________________________________________________________________
// 
// Fonction qui renvoie un pointeur vers une nouvelle chaine de caractere ou les
// 2 chaines sources transmisent en parametre sont assemblees.
// 
// -----------------------------------------------------------------------------
// 
// Controle si les deux chaines sources existent bien. Si l'une des deux chaine 
// est inexistante, return l'autre.
// Creation de la zone de memoire avec la taille des deux sources +1 ('\0') et
// le type (char).
// Controle si l'allocation s'est bien passee.
// Puis avec 2 boucles qui se suivent, copie de la source 1 et 2 dans la
// nouvelle chaine (dest) + rajout de '\0' a la fin.
// Les 2 free(s1) ont ete rajoutes pour resoudre un probleme de liberation de
// memoire pour le gnl. (free l'ancienne str avant devenir les nouvelle)

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}
// _____________________________________________________________________________
// 
// Fonction qui initialise l'enssemble des variables de la structure "game".
// 
// -----------------------------------------------------------------------------
// 
// Si c'est un pointeur -> NULL
// Si c'est un int, long int -> 0
// Je pense pas que ce soit primordiale d'initialiser les int long int car la
// structure "game" est dans la stack. (pas d'allocation dynamique) Mais ca rend
// le programme plus robuste dans le sens ou si une variable est utilisee avant
// sont initialisation locale, elle va pas donner une valeur random.
// Pareil pour les pointeurs... Seul le double tableau map est obligatoire pour
// ne pas avoir des problemes de liberation de memoire dans la fonction ft_free.
// j'avoue que c'est pas claire pour moi.
//
// En tout cas je trouve que l'initialisation de l'ensemble des variables de la
// struct est plus propre.
// 
// conclusion -> IL FAUT INITIALIER TOUTES LES VARIABLES MEME DANS LES STRUCT !

void	ft_initialisation_structs(t_game *game)
{
	game->map.tab_map = NULL;
	game->map.col_map = 0;
	game->map.line_map = 0;
	game->map.exit_counter = 0;
	game->map.collectible_counter = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.movements = 0;
	game->player.p_loose.img = NULL;
	game->player.p_win.img = NULL;
	game->player.p_and_e.img = NULL;
	game->graph.e_close.img = NULL;
	game->graph.mlx_ptr = NULL;
	game->graph.win_ptr = NULL;
	game->graph.flag_refresh = 0;
	game->graph.wall.img = NULL;
	game->graph.floor.img = NULL;
	game->graph.c.img = NULL;
	game->graph.e_open.img = NULL;
}
