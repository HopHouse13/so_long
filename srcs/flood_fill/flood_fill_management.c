/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:14:23 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/01 20:27:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// Fonction qui gere les differentes etapes du controle de la map.
// 
// -----------------------------------------------------------------------------
// 
// 1] appel de la fonction d'initialisation de la nouvelle struct map_ff 
// declaree au-dessus.
// 2] appel de la fonction flood_fill pour controler si la map est finissable.
// 3] si le nb de collectible ou le nombre de exit n'est pas a zero, la map
// n'est pas finissable.
// 4] appel de la fonction qui gere les messages d'erreurs avec le bon
// code d'erreur.
// 5] Avant de cloturer la fonction, la fonction pour free le double tableau de
// la struct map_ff.
// Cette structure map_ff a ete declaree uniquement dans cette fonction et doit
// etre free avant de quitter cette fonction.

int	ft_flood_fill_manag(t_game *game)
{
	t_map	map_ff;

	ft_initialisation_struct_ff(game, &map_ff);
	ft_flood_fill(game, &map_ff, game->player.y, game->player.x);
	if (map_ff.collectible_counter != 0 || map_ff.exit_counter != 0)
	{
		if (map_ff.collectible_counter != 0)
			ft_error_messages_ff(1);
		if (map_ff.exit_counter != 0)
			ft_error_messages_ff(2);
		ft_free_ff_map(&map_ff);
		return (0);
	}
	ft_free_ff_map(&map_ff);
	return (1);
}
