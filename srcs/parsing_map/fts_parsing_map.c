/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:13:57 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 01:40:33 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
// ok
int	ft_rectangular(t_game *map)
{
	int	i;
	int	nb_of_char;

	i = 0;
	nb_of_char = ft_strlen(map->tab_map[i]);
	while (map->tab_map[i])
	{
		if (nb_of_char != ft_strlen(map->tab_map[i]))
			return (1);
		i++; // nb de ligne dans le fichier
	}
	map->col_map = ft_strlen(map->tab_map[0]) - 1; // -1 car strlen compte le '\0' et je veux avoir uniquement le format de la map. 
	map->line_map = i; // inialisation du format de la map dans la variable "map"
	return (0);
}

// ok
int	ft_surrounded_by_walls(t_game *map)
{
	int	i;
	int	nb_of_lines;
	int	nb_of_char;

	nb_of_lines = 0;
	while (map->tab_map[nb_of_lines])
		nb_of_lines++;
	nb_of_lines--; // parce que index de la premiere ligne commence a 0 et pas 1.
	nb_of_char = ft_strlen(map->tab_map[0]);
	nb_of_char--; // meme principe: le dernier caractere se trouve a l' index (nb de caracteres - 1)
	i = -1;
	while (++i < nb_of_char)
		if (map->tab_map[0][i] != '1' || map->tab_map[nb_of_lines][i] != '1')
			return (1);
	i = 0; // pas la peine de recontreler la premiere ligne -> i va commencer a 1 (2eme ligne)
	while (++i < nb_of_lines) // nb_of_lines est a 4 -> ca evite de checker la derniere ligne inutilement
		if(map->tab_map[i][0] != '1' || map->tab_map[i][nb_of_char - 1] != '1') // le dernier caractere est au niveau de d'index(nb de caractere - 1) -> -1
			return (1);
	return (0);
}

// ok
int	ft_player_exists(t_game *map)
{
	int	i;
	int	j;
	int	nb_of_player;

	nb_of_player = 0;
	i = 0;
	while (map->tab_map[i])
	{
		j = 0;
		while (map->tab_map[i][j])
		{
			if (map->tab_map[i][j] == 'P')
			{
				nb_of_player++;
				map->col_player = j;
				map->line_player = i;
			}
			j++;
		}
		i++;
	}
	if (nb_of_player != 1)
		return (1);
	return (0);
}

// ok
int	ft_exit_exists(t_game *map)
{
	int	i;
	int	j;
	int	nb_of_exit;

	nb_of_exit = 0;
	i = 0;
	while (map->tab_map[i])
	{
		j = 0;
		while (map->tab_map[i][j])
		{
			if (map->tab_map[i][j] == 'E')
			{
				nb_of_exit++;
				map->col_exit = j;
				map->line_exit = i;
				map->exit_counter++;
			}
			j++;
		}
		i++;
	}
	if (nb_of_exit != 1)
		return (1);
	return (0);
}

// ok
int	ft_collectible_exists(t_game *map)
{
	int	i;
	int	j;
	int	nb_of_collectable;

	nb_of_collectable = 0;
	i = 0;
	while (map->tab_map[i])
	{
		j = 0;
		while (map->tab_map[i][j])
		{
			if (map->tab_map[i][j] == 'C')
				nb_of_collectable++;
			j++;
		}
		i++;
	}
	if (nb_of_collectable < 1)
		return (1);
	map->collectible_counter = nb_of_collectable; // itialisation du nb de collectives dans la variable "map"
	return (0);
}


