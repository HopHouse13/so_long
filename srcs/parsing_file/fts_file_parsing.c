/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_file_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:22:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/26 19:24:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_is_not_a_directory(char *name_map)
{
	int	fd;

	fd = open(name_map, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	else
		return (0);
}

int	ft_existing_file(char *name_map)
{
	int	fd;

	fd = open(name_map, O_RDONLY);
	if (fd == -1)
		return (1);
	else
	{
		close(fd);
		return (0);
	}
}

int	ft_valid_extension(char *name_map)
{
	int	size;

	size = ft_strlen(name_map);
	if (size < 4
		|| name_map[size - 4] != '.'
		|| name_map[size - 3] != 'b'
		|| name_map[size - 2] != 'e'
		|| name_map[size - 1] != 'r')
		return (1);
	else
		return (0);
}
/* int	ft_file_not_openable(char *name_map)
{
	
	return (0);
} */

int	ft_empty_file(char *name_map)
{
	int		fd;
	char	buffer[1];

	fd = open(name_map, O_RDONLY);
	if ((read(fd, buffer, 1)) == 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
