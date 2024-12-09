/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:32:10 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 01:25:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* if (map->ff->tab_map[line + 1][col] == '1' && map->ff->tab_map[line - 1][col] == '1' &&
		map->ff->tab_map[line][col + 1] == '1' &&  map->ff->tab_map[line][col - 1] == '1')
		return (0);
	else  */
int	ft_flood_fill(t_game *map, int line, int col)
{//printf("line[%d]col[%d]\n", line, col);//sleep(1);
	if (map->ff->collectible_counter == 0 && map->ff->exit_counter == 0)
		return (0);
	if (map->ff->tab_map[line][col] == 'C')
		map->ff->collectible_counter--;
	if (map->ff->tab_map[line][col] == 'E')
		map->ff->exit_counter--;
	map->ff->tab_map[line][col] = '1';
	if (map->ff->tab_map[line + 1][col] != '1')
		ft_flood_fill(map, line + 1, col);
	if (map->ff->tab_map[line - 1][col] != '1')
		ft_flood_fill(map, line - 1, col);
	if (map->ff->tab_map[line][col + 1] != '1')
		ft_flood_fill(map, line, col + 1);
	if (map->ff->tab_map[line][col - 1] != '1')
		ft_flood_fill(map, line, col - 1);
	return (0);
}

void	ft_initialisation_struct_ff(t_game *map)
{
	map->ff->tab_map = ft_make_ff_map(map);
	map->ff->col_map = map->col_map;
	map->ff->line_map = map->line_map;
	map->ff->col_player = map->col_player;
	map->ff->line_player = map->line_player;
	map->ff->col_exit = map->col_exit;
	map->ff->line_exit = map->line_exit;
	map->ff->exit_counter = map->exit_counter;
	map->ff->collectible_counter = map->collectible_counter;
}

char	**ft_make_ff_map(t_game *map)
{
	int		i;
	char	**ff_map;

	ff_map = malloc((map->line_map + 1) * sizeof(char *));
	if (!map->tab_map)
		return (NULL);
	i = -1;
	while (++i < map->line_map)
		ff_map[i] = ft_strdup(map->tab_map[i]);
	ff_map[i] = NULL;
	return (ff_map);
}
