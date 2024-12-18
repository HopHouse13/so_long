/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/19 00:00:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// PAUL <3 Quand on free le pointeur de la struct -> faut il free toutes 
// les pointeurs a l'interieur avant? ou useless?
int	main(int ac, char **av)
{
	t_game	*game;
	
	if (ac == 2)
	{
		if (ft_file_parsing_manag(av[1])) // fichier valide
		{
			game = malloc(sizeof(t_game));
			if (game && ft_map_parsing_manag(av[1], game)) // map valide
				if (ft_flood_fill_manag(game)) // jouabilite valide
				{
					printf(CYAN"[parsing & flood fill -> OK]\n"RESET);
					ft_so_long(game);
					ft_free_double_tab(game->map.ff->tab_map);
					free(game->map.ff);
					ft_free_double_tab(game->map.tab_map);
					free(game);
					return (0);
				}
		}
		return (1);
	}
	else
	{
		write(2, RED"Error\nNombre d'arguments incorrect.\n"RESET, 41);
		return (1);
	}
}
