/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:24:31 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/05 23:41:28 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "so_long.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h> // malloc
# include <stdio.h> // printf -> A SUPP

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct	s_ff
{
	t_game		*ff_map;
	char		fill;
}				t_ff;

typedef struct	s_game
{
	char 		**tab_map;
	t_ff		*ff;
	int			x;
	int			y;
	int			map_width; // largeur de la map
	int			map_height; // hauteur de la map
	int			abscisse_player;
	int			ordonnee_player;
	int			abscisse_exit;
	int			ordonnee_exit;
	int			collectible_counter; // compteur de collectibles
}				t_game;

// Fonctions du parsing du fichier

int		ft_file_parsing_manag(char *file);
int		ft_is_not_a_directory(char *file);
int		ft_existing_file(char *file);
int		ft_valid_extension(char *file);
int		ft_file_not_openable(char *file);
int		ft_empty_file(char *file);

// Fonctions du parsing de la map

int		ft_map_parsing_manag(char *file, t_game *map);
int		ft_rectangular(t_game *map);
int		ft_surrounded_by_walls(t_game *map);
int		ft_player_exists(t_game *map);
int		ft_exit_exists(t_game *map);
int		ft_collectible_exists(t_game *map);

// Fonctions creation de la map

void	ft_initialisation_struct_map(t_game *map);
void	ft_make_tab_map(char *file, t_game *map);
int		ft_line_counter(char *file);
char	*ft_strdup(const char *s_src);

// Flood_fill

void	itialisation_flood_fill(t_game *map);

// fonction de la gestion des messages d'erreurs

void	ft_error_messages_manag(int code_error);

// Tools

int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str, char *buffer);
void	ft_free_double_tab(char **map);
// int		ft_line_character_counter(char *file);

// gnl

char	*get_next_line(int fd);
char	*ft_before_line_break(char *str);
char	*ft_after_line_break(char *str);

#endif