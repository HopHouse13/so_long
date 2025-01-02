/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:26:53 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/02 17:13:57 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"
// _____________________________________________________________________________
// 
// Fonction pour initialiser un double tableau "map" a partir des retours de GNL
// et le fichier .ber de la map.
//
// -----------------------------------------------------------------------------
// 
// 1] nb_line prend la valeur de retour de ft_line_counter (fonction qui compte
// le nombre de ligne dans le fichier .ber)
// 
// 2] Initialisation du tableau principal avec un malloc + nb_line + (char *)
// car c'est une tableau de pointeur. Chaque case memoire sera un pointeur qui
// pointe vers une chaine de caractere.
//
// 3] Verification si l'allocation s'est bien passee.
//
// 4] Ouverture du fichier .ber avec open en only lecture et fd recupere le 
// file descriptor du fichier. fd fait maintenant le lien avec le fichier.ber et
// le programme.
//
// 5] Controle si l'ouverture du fichier s'est bien passee.
//
// 6] Initialisation de i a -1 car l'incrementation se fait dans la condition de
// boucle en prenier (avant que la condition soit controlee).
// Cela permet de faire correspondre l'indexe 0 au premier cycle de boucle.
//
// 7] Boucle pour transferer les lignes lu par GNL dans chaque chaine de
// caractere de tab_map via ft_strdup.
// La boucle se passe en 3 etapes:
//
// - lecture de GNL puis retour d'une ligne complete du fichier qui est stockee
// dans line.
// - duplication de cette ligne via ft_strdup qui renvoie un pointeur vers la
// chaine de caractere remplit avec "line" dans le tableau principal a l'indexe
// respectif de l'ordre des lignes lus.
// - liberation de line pour que au deuxieme cycle de la bouclem, elle soit
// disponible pour acceuillir la ligne suivante.
//
// Dans la condition de la boucle "i" doit etre egale au nombre de ligne total.
// Normalement comme il y a toujours un decalage de 1 entre le nombre d'element
// et l'indexe (qui commence a 0 et pas 1), il faudrait ecrire comme condition:
// ++i < nb_line pour avoir le meme nombre de cycle que de ligne.
//
// Sauf que GNL a besoin un appel supplementaire ou il n'y a rien a lire pour 
// la liberation de toutes les allocation de memoire necessaire.
// C'est pour ca, qu'il y a un cycle de plus par rapport au nombre de ligne.
// Comme il y a un plus rien a lire, GNL renvoie un pointeur = NULL qui est
// dupliquer dans la derniere case du tableau principal. Cela permet de signaler
// la fin de la serie de pointeurs que representent les lignes de la map.
// Chaque ligne a l'enssemble des caracteres que compose la ligne. Chaque
// caractere represente une colonne de la map.

// 8] Enfin le fd est libere avec la fonction close.

void	ft_make_tab_map(char *file, t_game *game)
{
	int		i;
	char	*line;
	int		fd;
	int		nb_line;

	nb_line = ft_line_counter(file);
	game->map.tab_map = malloc((nb_line + 1) * sizeof(char *));
	if (!game->map.tab_map)
		return ;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	i = -1;
	while (++i <= nb_line)
	{
		line = get_next_line(fd);
		game->map.tab_map[i] = ft_strdup(line);
		free(line);
	}
	close(fd);
	return ;
}
// _____________________________________________________________________________
// 
// Fonction qui compte le nombre de ligne dans le fichier en parametre d'entree
// du programme.
//
// -----------------------------------------------------------------------------
// 
// 1] Ouverture du fichier avec open et stockage du file descriptor dans fd
// + check si ca a bien fonctionne.
//
// 2] Stockage de la premiere ligne lu par GNL dans "line". Cela permet a
// pouvoir rentrer dans la boucle qui suit.
//
// 3] Initialisation de number_of_line a 0. Ca sera notre compteur de ligne.
//
// 4] Boucle, tant que "line" n'est pas NULL.
// - incrementation de number_of_line.
// - liberation de "line".
// - Stockage de la ligne suivante dans "line"
// Contrairement dans la fonction au-dessus, Nous voulons avoir le meme nombre
// de cycle que de lignes. C'est pour ca que cela s'arrete quand "line" == NULL.
// Des qu'on rentre dans la boucle, on incremente immediatement car "line" a
// deja la ligne 1.
//
// 5] liberation de "line" apres la boucle avec la fonction free. "line" qui est
// egale a NULL car plups rien a lire.
// 
// 6] Liberation du fd.
//
// 7] return notre compteur de ligne (number_of_line)

int	ft_line_counter(char *file)
{
	char	*line;
	int		number_of_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	number_of_line = 0;
	while (line != NULL)
	{
		number_of_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (number_of_line);
}
// _____________________________________________________________________________
// 
// Fonction qui duplique la chaine de caractere transmise en parametre d'entree.
//
// -----------------------------------------------------------------------------
// 
// Fonction standard de la libft.

char	*ft_strdup(const char *s_src)
{
	char	*s_dup;
	size_t	i;

	if (s_src == NULL)
		return (NULL);
	s_dup = malloc(sizeof(char) * ft_strlen(s_src) + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s_src[i])
	{
		s_dup[i] = s_src[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
