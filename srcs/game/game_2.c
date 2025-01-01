/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:29:13 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/01 20:47:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

// _____________________________________________________________________________
// 
// La fonction sere a fermer proprement la fenetre du jeu.
// 
// -----------------------------------------------------------------------------
// 
// Lors ce que mlx_hook qui s'occupe de scruter si il y a une clic sur la croix
// de la fenetre, detecte une clic sur cette croix, ft_cross_management est
// appelee.
// Elle verifie si le pointeur de la fenetre est toujours non NULL. Cela veut
// dire que la fenetre est toujours active.
// Si elle l'est, mlx_loop_end est appelee. Cette fonction vient de la mlx. Elle
// stoppe proprement mlx_loop (la boucle d'evenement active).

int	ft_cross_management(t_game *game)
{
	if (game->graph.win_ptr)
		mlx_loop_end(game->graph.mlx_ptr);
	return (0);
}
