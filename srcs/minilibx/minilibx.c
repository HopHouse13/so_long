/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:02 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/18 01:53:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_so_long()
{
	t_graph	*mlx;
	
	mlx = malloc(sizeof (t_graph));
	mlx->win_l = 1920;
	mlx->win_h = 1080;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_l, mlx->win_h, "Hello So_long");
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx_ptr, "./sprites/wall.xpm", &mlx->wall.l, &mlx->wall.h);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->wall.img, 100, 100);
	mlx_loop(mlx->mlx_ptr);
	
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