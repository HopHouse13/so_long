/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:53:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/29 02:33:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

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
	dest[i] = str[i];
	return (dest);
}

char	*ft_after_line_break(char *str)
{
	char	*dest1;
	int		i;
	int		j;

	i = 0;
	if (str[i] == 0)
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest1 = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!dest1)
		return (NULL);
	j = 0;
	while (str[i])
		dest1[j++] = str[++i];
	free(str);
	str = NULL;
	return (dest1);
}

char	*make_line_brut(int fd, char *str)
{
	char		*buffer;
	int			nb_octets_read;

	buffer = ft_calloc(64 + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nb_octets_read = 1;
	while (nb_octets_read > 0 && !(ft_strchr(str, '\n')))
	{
		nb_octets_read = read(fd, buffer, 64);
		if (nb_octets_read == -1)
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
		return (free(rest), rest = NULL, NULL);
	if (!rest)
	{
		rest = ft_calloc(1, 1);
		if (!rest)
			return (NULL);
	}
	rest = make_line_brut(fd, rest);
	line_to_print = ft_before_line_break(rest);
	rest = ft_after_line_break(rest);
	return (line_to_print);
}