/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/26 20:12:30 by ubuntu           ###   ########.fr       */
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
		ft_initialisation_structs(&game);
		if (ft_file_parsing_manag(av[1]) &&
			ft_map_parsing_manag(av[1], &game) &&
			ft_flood_fill_manag(&game) &&
			ft_game_start(&game))
		{
			ft_free_img(&game);
			ft_free(&game);
			return (0);
		}
		ft_free_img(&game);
		ft_free(&game);
		return (1);
	}
	else
	{
		write(2, RED"Error\nNombre d'arguments incorrect.\n"RESET, 41);
		return (1);
	}
}
