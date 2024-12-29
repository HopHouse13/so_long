/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:13:57 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 05:15:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_rectangular(t_game *game)
{
	long int	i;
	int			nb_of_col;
	
	nb_of_col = ft_strlen(game->map.tab_map[0]);
	i = -1;
	while (game->map.tab_map[++i])
		if (nb_of_col != ft_strlen(game->map.tab_map[i]))
			return (1);
	game->map.col_map = ft_strlen(game->map.tab_map[0]); // -1 car strlen compte le '\0' et je veux avoir uniquement le format de la map.
	game->map.line_map = i; // inialisation du format de la map dans la variable "map"
	return (0);
}

int ft_out_of_screen_format(t_game *game)
{
	if (game->map.col_map * ELEM_SIZE > SCREEN_LENGHT || game->map.line_map * ELEM_SIZE > SCREEN_WILTH)
		return (1);
	return (0);
}

int	ft_surrounded_by_walls(t_game *game)
{
	int	i;
	
	i = -1;
	while (++i < game->map.col_map)
	{//printf("nombre de ligne[%ld]\n", game->map.line_map);//printf("premiere ligne[%c]\tderniere ligne[%c]\n\n", game->map.tab_map[0][i], game->map.tab_map[game->map.line_map - 1][i]);
		if (game->map.tab_map[0][i] != '1' || game->map.tab_map[game->map.line_map - 1][i] != '1') // -1 car on passe en indexe (1eme ligne -> indexe 0)
			return (1);
	}
	i = 0; // pas la peine de contreler la premiere ligne -> i va commencer a 1 (2eme ligne)
	while (++i < game->map.line_map - 1) // "-1" evite de check la derniere ligne inutilement (deja check)
		if(game->map.tab_map[i][0] != '1' || game->map.tab_map[i][game->map.col_map - 1] != '1') // le dernier caractere est au niveau de d'index(nb de caractere - 1) -> -1
			return (1);
	return (0);
}

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
				game->player.x_player = j;
				game->player.y_player = i;
			}
			j++;
		}
		i++;
	}
	if (nb_of_player != 1)
		return (1);
	return (0);
}

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

