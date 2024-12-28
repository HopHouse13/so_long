/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:53:58 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/27 20:25:21 by ubuntu           ###   ########.fr       */
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

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
	{
		free (s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

void	ft_initialisation_structs(t_game *game)
{	
	game->map.tab_map = NULL;
	game->map.col_map = 0;
	game->map.line_map = 0;
	game->map.exit_counter = 0;
	game->map.collectible_counter = 0;
	game->player.x_player = 0;
	game->player.y_player = 0;
	game->player.movements = 0;
	game->player.p_loose.img = NULL;
	game->player.p_win.img = NULL;
	game->player.p_and_e.img = NULL;
	game->graph.mlx_ptr = NULL;
	game->graph.win_ptr = NULL;
	game->graph.flag_refresh = 0;
	game->graph.wall.img = NULL;
	game->graph.floor.img = NULL;
	game->graph.c.img = NULL;
	game->graph.e_open.img = NULL;
	game->graph.e_close.img = NULL;
	game->player.p_loose.img = NULL;
	game->player.p_and_e.img = NULL;
}
