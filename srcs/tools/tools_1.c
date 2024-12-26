/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:22 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/26 17:01:29 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// fonction fonctionnelle (n'est plus a verifier)
// n'est pas utilisee pour le moment
/* int	ft_line_character_counter(char *file)
{
	int		number_character;
	char	*one_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
		return (0);
	one_line = get_next_line(fd);
	number_character = 0;
	while (one_line[number_character])
		number_character++;
	number_character--; // car il compte aussi le '\0' et nous voulons uniquement le nombre de caractere.
	while (one_line != NULL) // je finis de lire la globalite de la map car si je lis une seule ligne avec gnl, le reste (dans gnl) de la ligne suivante n'est pas libere. solution bien trop complique pour faire autremment.(-> declaration de pointeur de pointeur de 'rest' dans cette fonction pour elle doit etre transmise a gnl en **rest).
	{
		free(one_line);
		one_line = get_next_line(fd);
	}
	free(one_line);
	close(fd);
	return (number_character);
} */
void ft_free_img(t_game *game)
{
	if(game->player.p_loose.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->player.p_loose.img);
	if(game->player.p_win.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->player.p_win.img);
	if(game->player.p_and_e.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->player.p_and_e.img);
	if(game->graph.wall.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->graph.wall.img);
	if(game->graph.floor.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->graph.floor.img);
	if(game->graph.c.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->graph.c.img);
	if(game->graph.e_open.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->graph.e_open.img);
	if(game->graph.e_close.img)
		mlx_destroy_image(game->graph.mlx_ptr,game->graph.e_close.img);
}
void	ft_free(t_game *game)
{
	long int	i;

	i = game->map.line_map - 1; // car on parle d'indexe et pas de nombre de lignes, decale de 1.
	while (i >= 0)
		free(game->map.tab_map[i--]);
	free(game->map.tab_map);
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

void	ft_putchar(char c)
{
	write(1, &c	, 1);
}

void	ft_putnbr_and_return_to_line(long int nb)
{
	char	resul[21]; // le max de chiffre dans une long int est 19 + '\n' + '\0'
	int		k;

	if (nb == 0)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return ;
	}
	k = 20;
	resul[k] = '\0'; // caractere de fin de chaine
	k--;
	resul[k] = '\n'; // retour a la ligne a chaque numero affiche
	while (nb > 0)
	{
		resul[--k] = (nb % 10) + '0';
		nb /= 10;
	}	
	while (resul[k])
		ft_putchar(resul[k++]);
}
