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
	printe(cub->params->map);
	cube_it(cub);
}
