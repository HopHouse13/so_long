/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:26:53 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/03 00:35:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

char	**ft_make_tab_map(char *file)
{
	char	 **map;
	int		i;
	char	*line;
	int		fd;
	int		nb_line;

	nb_line = ft_line_counter(file);
	map = malloc((nb_line + 1) * sizeof(char *));
	if (!map)
		return(NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
		return (ft_free_double_tab(map), NULL);
	i = 0;
	while (i < nb_line)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line);
		free(line);
		i++;
	} 
	map[i] = NULL;
	i = 0;
	close(fd);
	return (map);
}
// fonction fonctionnelle(n'est plus a verifier)

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

void	ft_free_double_tab(char **map)
{
	int	i;
	
	i = 0;
	while(map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

