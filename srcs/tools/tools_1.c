/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:22 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/02 15:28:59 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui libere la memoire ou sont stokees les visuels.
// -----------------------------------------------------------------------------
// 
// Si le pointeur du visuel n'est pas NULL, appel de mlx_destroy_image avec
// comme parametre, le pointeure mlx (connection avec la bibliotheque) +
// le pointeur du visuel en question.

void	ft_free_img(t_game *game)
{
	if (game->player.p_loose.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->player.p_loose.img);
	if (game->player.p_win.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->player.p_win.img);
	if (game->player.p_and_e.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->player.p_and_e.img);
	if (game->graph.wall.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->graph.wall.img);
	if (game->graph.floor.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->graph.floor.img);
	if (game->graph.c.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->graph.c.img);
	if (game->graph.e_open.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->graph.e_open.img);
	if (game->graph.e_close.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->graph.e_close.img);
}
// _____________________________________________________________________________
// 
// Fonction qui controle si la memoire du double tableau de la map ou le 
// pointeur de la mlx ou celui de la window doivent etre liberer.
// Elle gere egalement l'appel de ft_free_img (pour la liberation des images)
//
// -----------------------------------------------------------------------------
// 
// Pour le double tableau, simple boucle avec une incrementation pour free
// chaque pointeur de chaque sous tableau. Ne pas oublier le free egalement le
// le pointeur de tableau principale (le tableau de pointeurs)
//
// Appel ft_free_img pour la liberration des images.
//
// 2 if pour liberer le pointeur de la window et de la mlx. Si ils sont pas
// NULL -> free

void	ft_free(t_game *game)
{
	long int	i;

	i = -1;
	if (game->map.tab_map)
	{
		while (game->map.tab_map[++i])
			free(game->map.tab_map[i]);
		free(game->map.tab_map);
	}
	ft_free_img(game);
	if (game->graph.win_ptr)
	{
		mlx_destroy_window(game->graph.mlx_ptr, game->graph.win_ptr);
		game->graph.win_ptr = NULL;
	}
	if (game->graph.mlx_ptr)
	{
		mlx_destroy_display(game->graph.mlx_ptr);
		free(game->graph.mlx_ptr);
		game->graph.mlx_ptr = NULL;
	}
}
// _____________________________________________________________________________
// 
// Fonction la plus basique. Elle appelle write donc le but est d'afficher le
// caractere transmis en parametre d'entree selon le FilesDescriptor.
// 
// -----------------------------------------------------------------------------
// 
// FD standards :
//
// 0 -> stdin (ce que l'utilisateur tape)
// 1 -> stdout (pour afficher sur le terminal)
// 2 -> stderr (pour afficher des erreurs sur le terminal, cela permet qu'une
// trace de l'erreur s'inscrit dans un fichier .log. Fichier qui repertorie
// l'enssemble des erreurs.)
//
// Commande pour savoir combien de FD votre systeme peut ouvrir silmultanement:
// -> ulimit -n
//
// Vous pouvez modifier tamporairement le nombre de FD disponible en rajoutant
// apres cette commande le nombre que vous desirez.
//
// exemple : ulimit -n 2048

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// _____________________________________________________________________________
// 
// Fonction pour afficher sur le terminal (stdout (1)) la valeur en int tranmis
// en parametre d'entree. + un saut de ligne.
// 
// -----------------------------------------------------------------------------
// 
// ft_putnbr literatif clasique qui ne gere pas les negatifs et rajoute un '\n'
// a la fin.
//
// Particularitee -> utilisation du chaine de caractere char avec une taille
// statique.
// Elle est de 19 (taille max d'un long int) + 2 ('\n' + '\0').

void	ft_putnbr_and_return_to_line(long int nb)
{
	char	resul[21];
	int		k;

	if (nb == 0)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return ;
	}
	k = 20;
	resul[k] = '\0';
	k--;
	resul[k] = '\n';
	while (nb > 0)
	{
		resul[--k] = (nb % 10) + '0';
		nb /= 10;
	}
	while (resul[k])
		ft_putchar(resul[k++]);
}
