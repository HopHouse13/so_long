/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:53:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/26 19:58:07 by ubuntu           ###   ########.fr       */
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

char	*ft_after_line_break(char *str) // ma fonction de mon gnl
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	if (str[i] == 0)
		return (free(str), str = NULL, str);
	while (str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while (str[i])
		dest[j++] = str[++i];
	free(str);
	str = NULL;
	return (dest);
}

//>>>>>>>>>> defference entre la mienne et celle de Paul --> la mienne 2 bytes encore dispo. Un seul pour celle de Paul

// char	*ft_after_line_break(char *line) // fonction de Paul 
// {
// 	int		i;
// 	char	*remainder_line;

// 	i = 0;
// 	if (line != NULL)
// 	{
// 		while (line[i] != '\n' && line[i] != '\0')
// 			i++;
// 		remainder_line = ft_substr(line, i + 1, ft_strlen(line));
// 		free(line);
// 		line = NULL;
// 		return (remainder_line);
// 	}
// 	else
// 		return (NULL);
// }
// char	*ft_substr(char const *s_src, int start, int len) // fonction pour la fonction de Paul
// {
// 	char	*s_new;
// 	int	i;
// 	int	j;

// 	if (!s_src)
// 		return (NULL);
// 	if (start >= ft_strlen(s_src))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s_src) - start)
// 		len = ft_strlen(s_src) - start;
// 	s_new = malloc((len + 1)* sizeof(char));
// 	if (!s_new)
// 		return (NULL);
// 	i = start;
// 	j = 0;
// 	while (s_src[i])
// 	{
// 		if (j < len)
// 			s_new[j++] = s_src[i];
// 		i++;
// 	}
// 	s_new[j] = '\0';
// 	return (s_new);
// }

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
	buffer = ft_calloc(30 + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nb_octets_read = 1;
	while (nb_octets_read > 0 && !(ft_strchr(str, '\n')))
	{
		nb_octets_read = read(fd, buffer, 30);
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
	{
		if (rest != NULL)
		{
			free(rest);
			rest = NULL;
		}
		return (NULL);
	}
	rest = make_line_brut(fd, rest);
	//printf(">>>> %d\n", ft_strlen(rest));
/* 	if (ft_strlen(rest) == 0)
	{
		free(rest);
		rest = NULL;
		return (rest);
	} */
	line_to_print = ft_before_line_break(rest);
	rest = ft_after_line_break(rest);
	return (line_to_print);
}
