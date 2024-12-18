/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:32:10 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/18 23:50:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

/* if (map.ff->tab_map[line + 1][col] == '1' && map.ff->tab_map[line - 1][col] == '1' &&
		map.ff->tab_map[line][col + 1] == '1' &&  map.ff->tab_map[line][col - 1] == '1')
		return (0);
	else  */
int	ft_flood_fill(t_game *game, int line, int col)
{
	if (game->map.ff->collectible_counter == 0 && game->map.ff->exit_counter == 0)
		return (0);
	if (game->map.ff->tab_map[line][col] == 'C')
		game->map.ff->collectible_counter--;
	if (game->map.ff->tab_map[line][col] == 'E')
		game->map.ff->exit_counter--;
	game->map.ff->tab_map[line][col] = '1';
	if (game->map.ff->tab_map[line + 1][col] != '1')
		ft_flood_fill(game, line + 1, col);
	if (game->map.ff->tab_map[line - 1][col] != '1')
		ft_flood_fill(game, line - 1, col);
	if (game->map.ff->tab_map[line][col + 1] != '1')
		ft_flood_fill(game, line, col + 1);
	if (game->map.ff->tab_map[line][col - 1] != '1')
		ft_flood_fill(game, line, col - 1);
	return (0);
}

void	ft_initialisation_struct_ff(t_game *game)
{
	game->map.ff->tab_map = ft_make_ff_map(game);
	game->map.ff->col_map = game->map.col_map;
	game->map.ff->line_map = game->map.line_map;
	game->map.ff->col_player = game->map.col_player;
	game->map.ff->line_player = game->map.line_player;
	game->map.ff->col_exit = game->map.col_exit;
	game->map.ff->line_exit = game->map.line_exit;
	game->map.ff->exit_counter = game->map.exit_counter;
	game->map.ff->collectible_counter = game->map.collectible_counter;
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
