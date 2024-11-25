/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:29:05 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/25 19:47:07 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		if (ft_file_parsing_management(av[1]) == 0) // fichier valide
			printf("[isOK]");/* if (ft_map_parsing_management(av[1]) == 0) // map validee
				ft_so_long(av[1]);
			else
			{
				ft_error_messages_management(ft_parsing_file(av[1]));
				return (1);	
			} */
		else
		{printf("[isDEAD]");
			// ft_error_messages_management(ft_parsing_file(av[1]));
			return (1);	
		}
	else
	{
		write(2, RED"Error\nNombre d'arguments incorrect.\n"RESET, 41);
		return (1);
	}
}
