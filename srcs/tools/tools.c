/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:53:58 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/03 00:35:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	int				i;
	if (count < 1 || size < 1)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (count > 0)
	{
		ptr[i] = '\0';
		i++;
		count--;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

// fonction fonctionnelle (n'est plus a verifier)
int	ft_line_character_counter(char *file)
{
	int		number_character;
	char	*one_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
		return (0);
	one_line = get_next_line(fd);
	number_character = 0;
	while (one_line[number_character])
		number_character++;
	number_character--; // car il compte aussi le '\0' et nous voulons uniquement le nombre de caractere.
	while (one_line != NULL) // je finis de lire la globalite de la map car si je lis une seule ligne avec gnl, le reste (dans gnl) de la ligne suivante n'est pas libere. solution bien trop complique pour faire autremment.(-> declaration de pointeur de pointeur de 'rest' dans cette fonction pour elle doit etre transmise a gnl en **rest).
	{
		free(one_line);
		one_line = get_next_line(fd);
	}
	free(one_line);
	close(fd);
	return (number_character);
}