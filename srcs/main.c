/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/03 22:36:32 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	main(int ac, char **av)
{	
	if (ac == 2)
	{
		if (ft_file_parsing_manag(av[1])
			|| ft_map_parsing_manag(av[1])
			|| ft_flood_fill_manag(void) == 0) // fichier, map, jouabilite valide
		{
			printf(CYAN"[isOK]\n"RESET);
			// ft_so_long(av[1]);
			return (0);
		}
		return (1);
	}
	else
	{
		write(2, RED"Error\nNombre d'arguments incorrect.\n"RESET, 41);
		return (1);
	}
}
