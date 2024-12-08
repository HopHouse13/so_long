/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:22 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/09 00:47:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// fonction fonctionnelle (n'est plus a verifier)
// n'est pas utilisee pour le moment
int	ft_line_character_counter(char *file)
{
	int		number_character;
	char	*one_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) // a confirmer l'utilite !!!!!!!!!!!!!!!!!!!!!!!!!
		return (0);
	one_line = get_next_line(fd);
	number_character = 0;
	while (one_line[number_character])
		number_character++;
	number_character--; // car il compte aussi le '\0' et nous voulons uniquement le nombre de caractere.
	while (one_line != NULL) // je finis de lire la globalite de la map car si je lis une seule ligne avec gnl, le reste (dans gnl) de la ligne suivante n'est pas libere. solution bien trop complique pour faire autremment.(-> declaration de pointeur de pointeur de 'rest' dans cette fonction pour elle doit etre transmise a gnl en **rest).
	{
		free(one_line);
		one_line = get_next_line(fd);
	}
	free(one_line);
	close(fd);
	return (number_character);
}
