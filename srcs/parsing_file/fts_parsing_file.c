/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_parsing_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:22:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 00:27:29 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_is_not_a_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}
// O_EXCL peut avoir un souci avec les lien symboliques selon les systemes. printf("[%d]\n", fd);

//-1 -> non creation -> fichier existe deja -> return (0)
// !-1 -> fichier inexistant -> creation du fichier -> return (1)
// unlink(file);
int	ft_existing_file(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_EXCL, 0777);
	if (fd != -1)
	{
		close(fd);
		unlink(file); // surement a supp. -> fonction interdite (elle supp. le fichier cree si il m'existe pas)
		return (1);
	}
	return (0);
}

int	ft_valid_extension(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size < 4
		|| file[size - 4] != '.'
		|| file[size - 3] != 'b'
		|| file[size - 2] != 'e'
		|| file[size - 1] != 'r')
		return (1);
	return (0);
}

int	ft_file_not_openable(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	ft_empty_file(char *file)
{
	int		fd;
	char	buffer[1];

	fd = open(file, O_RDONLY);
	if ((read(fd, buffer, 1)) == 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
