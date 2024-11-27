/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:24:31 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/27 02:09:33 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "so_long.h"
# include <unistd.h>
# include <fcntl.h>
// aSupp
# include <stdlib.h> // malloc
# include <stdio.h> // printf
//aSupp
# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct	s_map
{
	char 		**map;
}				t_map;

// Fonctions du parsing du fichier

int		ft_file_parsing_management(char *file);
int		ft_is_not_a_directory(char *file);
int		ft_existing_file(char *file);
int		ft_valid_extension(char *file);
int		ft_file_not_openable(char *file);
int		ft_empty_file(char *file);

// Fonctions du parsing de la map

int		ft_file_parsing_management(char *map)
// int		ft_rectangular(char *map);
// int		ft_surrounded_by_walls(char *map);
// int		ft_player_exists(char *map);
// int		ft_exit_exists(char *map);
// int		ft_collectible_exists(char *map);

// fonction de la gestion des messages d'erreurs

void	ft_error_messages_management(int code_error);

// Tools

int		ft_strlen(const char *s);

#endif