#include <cube3D.h>

int	mlx_initialize(t_cub *cube)
{
	cube->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Lil_cube", false);
	if (!cube->mlx)
		error_exit(E_MLX, cube);
	cube->frame = mlx_new_image(cube->mlx, W_WIDTH, W_HEIGHT);
	mlx_image_to_window(cube->mlx, cube->frame, 0, 0);
	animation_init(cube);
	return (0);
}

void	mlx_run(t_cub *lil_cub)
{
	mlx_initialize(lil_cub);
	mlx_loop_hook(lil_cub->mlx, &gameloop, lil_cub);
	mlx_loop(lil_cub->mlx);
	mlx_terminate(lil_cub->mlx);
}
