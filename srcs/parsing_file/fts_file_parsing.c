/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_parsing_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:22:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/25 18:39:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib/so_long.h"

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