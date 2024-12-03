/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:13:57 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/03 04:10:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
// ok
int	ft_rectangular(char **map)
{
	int	i;
	int nb_of_characters;
	
	i = 0;
	nb_of_characters = ft_strlen(map[i]);
	while (map[i])
	{
		if (nb_of_characters != ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}
// ok
int	ft_surrounded_by_walls(char **map)
{
	int	i;
	int	nb_of_lines;
	int nb_of_characters;
	
	nb_of_lines = 0;
	while (map[nb_of_lines])
		nb_of_lines++;
	nb_of_lines--; // parce que index de la premiere ligne commence a 0 et pas 1.
	nb_of_characters = ft_strlen(map[0]);
	nb_of_characters--; // meme principe: le dernier caractere se trouve a l' index (nb de caracteres - 1)
	i = -1;
	while (++i < nb_of_characters)
		if(map[0][i] != '1' || map[nb_of_lines][i] != '1')
			return (1);
	i = 0; // pas la peine de recontreler la premiere ligne -> i va commencer a 1 (2eme ligne)
	while (++i < nb_of_lines) // nb_of_lines est a 4 -> ca evite de checker la derniere ligne inutilement
		if(map[i][0] != '1' || map[i][nb_of_characters - 1] != '1') // le dernier caractere est au niveau de d'index(nb de caractere - 1) -> -1
			return (1);
	return (0);
}
// ok
int	ft_player_exists(char **map)
{
	int	i;
	int	j;
	int	nb_of_player;
	
	nb_of_player = 0;
	i = 0;
	while (map[i])
	{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'P')
					nb_of_player++;
				j++;
			}
		i++;
	}
	if (nb_of_player != 1)
		return (1);
	return (0);
}
// ok
int	ft_exit_exists(char **map)
{
	int	i;
	int	j;
	int	nb_of_exit;
	
	nb_of_exit = 0;
	i = 0;
	while (map[i])
	{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'E')
					nb_of_exit++;
				j++;
			}
		i++;
	}
	if (nb_of_exit != 1)
		return (1);
	return (0);
}
// ok
int	ft_collectible_exists(char **map)
{
	int	i;
	int	j;
	int	nb_of_collectable;
	
	nb_of_collectable = 0;
	i = 0;
	while (map[i])
	{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'C')
					nb_of_collectable++;
				j++;
			}
		i++;
	}
	if (nb_of_collectable < 1)
		return (1);
	return (0);
}

