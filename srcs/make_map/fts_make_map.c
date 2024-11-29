/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_make_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:00:20 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/29 04:01:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_line_counter(char *file)
{
	char 	*line;
	int		number_of_line;
	int		fd;
		
	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
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

int	ft_line_character_counter(char *file)
{
	int	number_character;
	char *one_line;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
		return (0);
	one_line = get_next_line(fd);
	number_character = 0;
	while (one_line[number_character])
		number_character++;
	number_character--; // car il compte aussi le '\0' et nous voulons uniquement le nombre de caractere.
	free(one_line);
	close(fd);
	return (number_character);
}

char **ft_init_values(char **map, char *file)
{
	int		i;
	int		j;
	char	*one_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
		return (0);
	i = 0;
	while(map[i])
	{
		one_line = get_next_line(fd);
		j = 0;
		while (one_line[j])
		{
			*map[j] = one_line[j];
			j++;
		}
		free(one_line);
		i++;
	}
	close(fd);
	return (map);
}

void	ft_free_double_tab(char **map)
{
	int	i;
	
	i = -1;
	while(map[++i])
		free(map[i]);
	free(map);
}
