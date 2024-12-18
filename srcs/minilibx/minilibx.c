/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/18 23:59:08 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_so_long(t_game *game)
{
	game->graph.win_l = 1920;
	game->graph.win_h = 1080;
	game->graph.mlx_ptr = mlx_init();
	game->graph.win_ptr = mlx_new_window(game->graph.mlx_ptr, game->graph.win_l, game->graph.win_h, "Hello So_long");
	if (ft_itialisation_img(game) == 1)
		return (1);
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.floor.img, 0, 0);
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.wall.img, 64, 0);
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_loose.img, 0, 64);
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.c.img, 128, 0);
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.e.img, 0, 128);
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.win_ptr, game->graph.p_win.img, 64, 64);
	mlx_loop(game->graph.mlx_ptr);
	return (0);
}

int	ft_itialisation_img(t_game *game)
{
	game->graph.wall.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/wall.xpm", &game->graph.wall.l, &game->graph.wall.h);
	if (!game->graph.wall.img)
		return (1);
	game->graph.floor.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/floor.xpm", &game->graph.floor.l, &game->graph.floor.h);
	if (!game->graph.floor.img)
		return (1);
	game->graph.c.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/c.xpm", &game->graph.c.l, &game->graph.c.h);
	if (!game->graph.c.img)
		return (1);
	game->graph.e.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/e.xpm", &game->graph.e.l, &game->graph.e.h);
	if (!game->graph.e.img)
		return (1);
	game->graph.p_loose.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_loose.xpm", &game->graph.p_loose.l, &game->graph.p_loose.h);
	if (!game->graph.p_loose.img)
		return (1);
	game->graph.p_win.img = mlx_xpm_file_to_image(game->graph.mlx_ptr, "./sprites/p_win.xpm", &game->graph.p_win.l, &game->graph.p_win.h);
	if (!game->graph.p_win.img)
		return (1);
	return (0);
}




/* int	ft_so_long()
{
	t_graph	*mlx;
// apres le malloc faut-il initialiser chaque valeur de la struct mlx?
	mlx = malloc(sizeof (t_graph));
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_LARGEUR, WINDOW_HAUTEUR, "so_long's window!");
	if (!mlx->win_ptr)
	{
		free(mlx->win_ptr); // pas sur de tout ca 
 		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (1);
	}
	//mlx_loop_hook(mlx->mlx_ptr, &handle_no_event, &mlx); // loop_hook ecoute les events???
	mlx_key_hook(mlx->win_ptr, &ft_input_manag, &mlx); // gestion des touche (quand elles sont relachees) -> action
	
	mlx_loop(mlx->mlx_ptr); // remplace le while pour garder la fenetre ouverte (l'instance?). A besoin du ptr de la lib
	
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	return (0);
}

// int	handle_no_event(t_graph *mlx)
// {
//     // This function needs to exist, but it is useless for the moment
//     return (0);
// }

int	ft_input_manag(int keysym, t_graph *mlx) // esc?
{
		if (keysym == XK_Escape)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (0);
} */