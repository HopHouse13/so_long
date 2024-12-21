/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/20 20:56:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PAUL <3 Quand on free le pointeur de la struct -> faut il free toutes 
#include "../lib/so_long.h"

// les pointeurs a l'interieur avant? ou useless?
int	main(int ac, char **av)
{
	t_game	game;
	
	if (ac == 2)
	{
		if (ft_file_parsing_manag(av[1])) // fichier valide
		{
			if (ft_map_parsing_manag(av[1], &game)) // map valide
				if (ft_flood_fill_manag(&game)) // jouabilite valide
				{
					ft_so_long(&game);
					return (0);
					ft_free_double_tab(game.map.tab_map);
				}
		}
		ft_free_double_tab(game.map.tab_map);
		return (1);
	}
	else
	{
		write(2, RED"Error\nNombre d'arguments incorrect.\n"RESET, 41);
		return (1);
	}
}
