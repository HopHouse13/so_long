/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:26:53 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 14:07:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	ft_initialisation_struct_map(t_game *map)
{
	map->ff = NULL;
	map->tab_map = NULL;
	map->col_map = 0;
	map->line_map = 0;
	map->col_player = 0;
	map->line_player = 0;
	map->col_exit = 0;
	map->line_exit = 0;
	map->exit_counter = 0;
	map->collectible_counter = 0;
	return ;
}

void	ft_make_tab_map(char *file, t_game *map)
{
	int		i;
	char	*line;
	int		fd;
	int		nb_line;

	nb_line = ft_line_counter(file);
	map->tab_map = malloc((nb_line + 1) * sizeof(char *));
	if (!map->tab_map)
		return ;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_free_double_tab(map->tab_map);
		return ;
	}
	i = -1; // pour gagner des lignes
	while (++i < nb_line)
	{
		line = get_next_line(fd);
		map->tab_map[i] = ft_strdup(line);
		free(line);
	}
	map->tab_map[i] = NULL;
	close(fd);
	return ;
}
// fonction fonctionnelle(n'est plus a verifier)

int	ft_line_counter(char *file)
{
	char	*line;
	int		number_of_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	number_of_line = 0;
	while (line != NULL)
	{
		number_of_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (number_of_line);
}

char	*ft_strdup(const char *s_src)
{
	char	*s_dup;
	size_t	i;

	s_dup = malloc(sizeof(char) * ft_strlen(s_src) + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s_src[i])
	{
		s_dup[i] = s_src[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
