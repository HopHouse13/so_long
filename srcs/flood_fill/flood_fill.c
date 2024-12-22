/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:32:10 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/23 00:54:18 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* if (map.ff->tab_map[line + 1][col] == '1' && map.ff->tab_map[line - 1][col] == '1' &&
		map.ff->tab_map[line][col + 1] == '1' &&  map.ff->tab_map[line][col - 1] == '1')
		return (0);
	else  */
int	ft_flood_fill(t_game *game, t_map *map_ff, int line, int col)
{
	if (map_ff->collectible_counter == 0 && map_ff->exit_counter == 0)
		return (0);
	if (map_ff->tab_map[line][col] == 'C')
		map_ff->collectible_counter--;
	if (map_ff->tab_map[line][col] == 'E')
		map_ff->exit_counter--;
	map_ff->tab_map[line][col] = '1';
	if (map_ff->tab_map[line + 1][col] != '1')
		ft_flood_fill(game, map_ff, line + 1, col);
	if (map_ff->tab_map[line - 1][col] != '1')
		ft_flood_fill(game, map_ff, line - 1, col);
	if (map_ff->tab_map[line][col + 1] != '1')
		ft_flood_fill(game, map_ff, line, col + 1);
	if (map_ff->tab_map[line][col - 1] != '1')
		ft_flood_fill(game, map_ff, line, col - 1);
	return (0);
}

void	ft_initialisation_struct_ff(t_game *game, t_map *map_ff)
{
	map_ff->tab_map = ft_make_ff_map(game);
	map_ff->col_map = game->map.col_map;
	map_ff->line_map = game->map.line_map;
	map_ff->exit_counter = game->map.exit_counter;
	map_ff->collectible_counter = game->map.collectible_counter;
}

char	**ft_make_ff_map(t_game *game)
{
	int		i;
	char	**ff_map;

	ff_map = malloc((game->map.line_map + 1) * sizeof(char *));
	if (!ff_map)
		return (NULL);
	i = -1;
	while (++i < game->map.line_map)
		ff_map[i] = ft_strdup(game->map.tab_map[i]);
	ff_map[i] = NULL;
	return (ff_map);
}
