#include <cube3D.h>

void printe(char **str)
{
	while (*str)
	{
		printf("%s\n", *str);
		str++;
	}
}

void	key_controls(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window((mlx_t *)cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->player->pang -= rad_convertor(5);
		if (cub->player->pang < 0)
			cub->player->pang += rad_convertor(360);
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->player->pang += rad_convertor(5);
		if (cub->player->pang > rad_convertor(360))
			cub->player->pang -= rad_convertor(360);
	}
	cube_it(cub);
}
