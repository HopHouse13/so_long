/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:22 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 05:06:54 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

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
	
	i = -1;
	if (game->map.tab_map)
	{
		while (game->map.tab_map[++i])
			free(game->map.tab_map[i]);
		free(game->map.tab_map);
	}
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
