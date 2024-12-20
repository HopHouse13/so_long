/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:24:31 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/21 00:03:56 by ubuntu           ###   ########.fr       */
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

# include <mlx.h> // minilibx
# include <X11/keysym.h>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

# define ELEM_SIZE 64

typedef struct	s_img
{
	void		*img; // ptr de l'image cree
	int			l;
	int			h;
}				t_img;

typedef struct s_player
{
	long int		x;
	long int		y;
	long int		movements;
	t_img			player;
}	t_player;

typedef struct	s_graph
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_l;
	int			win_h;
	t_img		wall;
	t_img		floor;
	t_img		c;
	t_img		e_open;
	t_img		e_close;
	t_img		p_loose;
	t_img		p_win;
}				t_graph;

typedef struct		s_map
{
	//struct s_map	*ff; // copie de la map pour le ff
	char 			**tab_map; // original_map
	int				col_map; // largeur de la map
	int				line_map; // hauteur de la map
	int				col_player;
	int				line_player;
	int				col_exit;
	int				line_exit;
	int				exit_counter; // compteur de d'exit
	int				collectible_counter; // compteur de collectibles
}					t_map;

typedef struct		s_game
{
	t_map			map;
	t_player		player;
	t_graph			graph;
}					t_game;


// Fonctions du parsing du fichier

int		ft_file_parsing_manag(char *file);
int		ft_is_not_a_directory(char *file);
int		ft_existing_file(char *file);
int		ft_valid_extension(char *file);
int		ft_file_not_openable(char *file);
int		ft_empty_file(char *file);

// Fonctions du parsing de la map

int		ft_map_parsing_manag(char *file, t_game *game);
int		ft_rectangular(t_game *game);
int		ft_surrounded_by_walls(t_game *game);
int		ft_player_exists(t_game *game);
int		ft_exit_exists(t_game *game);
int		ft_collectible_exists(t_game *game);
int		ft_other_elem(t_game *game);


// Fonctions creation de la map

void	ft_initialisation_struct_map(t_game *game);
void	ft_make_tab_map(char *file, t_game *game);
int		ft_line_counter(char *file);
char	*ft_strdup(const char *s_src);

// Flood_fill

int		ft_flood_fill_manag(t_game *game);
void	ft_initialisation_struct_ff(t_game *game, t_map *game_ff);
char	**ft_make_ff_map(t_game *game);
int		ft_flood_fill(t_game *game, t_map *map_ff, int x, int y);

// so_long

int		ft_so_long(t_game *game);
int		ft_itialisation_img(t_game *game);
void	ft_get_map(t_game *game, int i,int j);




// fonction de la gestion des messages d'erreurs

void	ft_error_messages_file_and_map(int code_error);
void	ft_error_messages_ff(int code_error);

// Tools

int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str, char *buffer);
void	ft_free_double_tab(char **map);
//void	ft_free(t_game *game);
// int		ft_line_character_counter(char *file);

// gnl

char	*get_next_line(int fd);
char	*ft_before_line_break(char *str);
char	*ft_after_line_break(char *str);

// gnl_test_A_SUPPRIMER

// char	*get_line_fd(int fd, char *line);
// char	*read_until_n(int fd, char *line, char *buffer, int bytes_red);
// char	*clean_line(char *line);
// char	*get_remainder(char *line);
// char	*ft_substr(char const *s_src, int start, int len);

#endif