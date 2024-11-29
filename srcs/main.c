/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/28 19:13:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_file_parsing_management(av[1]) == 0) // fichier valide
			if (ft_map_parsing_management(av[1]) == 0) // map validee
			{
				//printf(CYAN"[isOK]\n"RESET); /* ft_so_long(av[1]); */
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
