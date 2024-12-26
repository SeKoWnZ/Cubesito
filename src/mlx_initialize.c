#include <cube3D.h>

int	mlx_intialize(t_cub *cube)
{
	cube->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Lil_cube", false);
	if (!cube->mlx)
		error_exit(E_MLX, cube);
	mlx_texture_to_image()
}
