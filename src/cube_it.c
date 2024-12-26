#include <cube3D.h>

void	cube_it(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_image_t *frame;
	frame = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	while (j < W_HEIGHT/2)
	{
		i = 0;
		while (i < W_WIDTH)
		{
			mlx_put_pixel(frame, i, j, cub->params->c);
			i++;
		}
		j++;
	}
	while (j < W_HEIGHT)
	{
		i = 0;
		while (i < W_WIDTH)
		{
			mlx_put_pixel(frame, i, j, cub->params->f);
			i++;
		}
		j++;
	}
	mlx_image_to_window(cub->mlx, frame, 0, 0);
}
