/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:26:53 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/29 04:26:42 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	ft_make_tab_map(char *file)
{
	char	**map;
	int		i;
	// int		numbre_of_line;

	// numbre_of_line = ft_line_counter(file);
	// printf("[%d]\n", numbre_of_line);
	map = malloc((ft_line_counter(file) + 1) * sizeof(char *));
	if (!map)
		return ;
	map[ft_line_counter(file) + 1] = '\0';
	i = 0;
	while (i < ft_line_counter(file))
	{
		map[i] =malloc((ft_line_character_counter(file) + 1) * sizeof(char *));
		if (!map[i])
			return ;
		map[i][(ft_line_character_counter(file) + 1)] = '\0';
		i++;
	}
	map = ft_init_values(map, file);

	
/* 	int	j = 0;
	i = 0;
	while (map[]) */

	
	ft_free_double_tab(map);
	return ;
}