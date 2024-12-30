/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:53:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/29 19:22:33 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

char	*ft_before_line_break(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc(i + 2, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	//dest[i] = str[i]; // rajoute le saut de ligne
	return (dest);
}

// nouvelle fonction
char	*ft_after_line_break(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i]) // Si aucun '\n', rien à conserver
	{
		free(str);
		return (NULL);
	}
	dest = ft_calloc((ft_strlen(str) - i), sizeof(char)); // ft_strlen - i suffit
	if (!dest)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		dest[j++] = str[++i];
	free(str);
	return (dest);
}

char	*make_line_brut(int fd, char *str)
{
	char		*buffer;
	int			nb_octets_read;

	if (!str)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
	}
	buffer = ft_calloc(42 + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nb_octets_read = 1;
	while (nb_octets_read > 0 && !(ft_strchr(str, '\n')))
	{
		nb_octets_read = read(fd, buffer, 42);
		if (nb_octets_read == - 1)
			return (NULL);
		if (nb_octets_read == 0)
			break ;
		buffer[nb_octets_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line_to_print;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (rest != NULL)
		{
			free(rest);
			rest = NULL;
		}
		return (NULL);
	}
	rest = make_line_brut(fd, rest);
	line_to_print = ft_before_line_break(rest);
	rest = ft_after_line_break(rest);
	return (line_to_print);
}
