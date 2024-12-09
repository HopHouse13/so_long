/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 16:36:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// PAUL <3 Quand on free le pointeur de la struct -> faut il free toutes 
// les pointeurs a l'interieur avant? ou useless?
int	main(int ac, char **av)
{
	t_game	*map;

	if (ac == 2)
	{
		if (ft_file_parsing_manag(av[1])) // fichier valide
		{
			map = malloc(sizeof(t_game));
			if (map && ft_map_parsing_manag(av[1], map)) // map valide
				if (ft_flood_fill_manag(map)) // jouabilite valide
				{
					printf(CYAN"[isOK]\n"RESET);
					// ft_so_long();
					ft_free_double_tab(map->ff->tab_map);
					free(map->ff);
					ft_free_double_tab(map->tab_map);
					free(map);
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
