/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:22 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/24 00:05:45 by ubuntu           ###   ########.fr       */
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

void	ft_free(t_game *game)
{
	long int	i;

	i = game->map.line_map - 1; // car on parle d'indexe et pas de nombre de lignes, decale de 1.
	while (i != -1)
		free(game->map.tab_map[i--]);
	free(game->map.tab_map);
}
void	ft_initialisation_structs(t_game *game)
{	
	game->map.tab_map = NULL;
	game->map.col_map = 0;
	game->map.line_map = 0;
	game->map.exit_counter = 0;
	game->map.collectible_counter = 0;
	game->player.x_player = 0;
	game->player.y_player = 0;
	game->player.movements = 0;
	game->graph.mlx_ptr = NULL;
	game->graph.win_ptr = NULL;
	game->graph.flag_refresh = 0;
	game->graph.wall.img = NULL;
	game->graph.floor.img = NULL;
	game->graph.c.img = NULL;
	game->graph.e_open.img = NULL;
	game->graph.e_close.img = NULL;
	game->graph.p_loose.img = NULL;
	game->graph.p_win.img = NULL;	
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int nb)
{
	char	resul[20]; // le max de chiffre dans une long int est 19 + '\0'
	int		k;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	k = 19;
	resul[k] = '\0';
	while (nb > 0)
	{
		resul[--k] = (nb % 10) + '0';
		nb /= 10;
	}
	while (resul[k])
		ft_putchar(resul[k++]);
}
