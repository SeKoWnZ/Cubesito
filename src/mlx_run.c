/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:02:52 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:38 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	mlx_initialize(t_cub *cube)
{
	cube->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Lil_cube", false);
	if (!cube->mlx)
		error_exit(E_MLX, cube);
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cube->mlx, W_WIDTH / 2, W_HEIGHT / 2);
	cube->frame = mlx_new_image(cube->mlx, W_WIDTH, W_HEIGHT);
	if (!cube->frame)
		error_exit(E_MLX, cube);
	if (mlx_image_to_window(cube->mlx, cube->frame, 0, 0) < 0)
		error_exit(E_MLX, cube);
	animation_init(cube);
	return (0);
}

void	mlx_run(t_cub *lil_cub)
{
	mlx_initialize(lil_cub);
	mlx_loop_hook(lil_cub->mlx, &gameloop, lil_cub);
	mlx_loop(lil_cub->mlx);
}
