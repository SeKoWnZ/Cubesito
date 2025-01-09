#include <cube3D.h>

void	ceilingfloor(t_cub *cub, mlx_image_t *frame, int *i)
{
	int	j;

	j = 0;
	while (j < W_HEIGHT/2)
	{
		mlx_put_pixel(frame, *i, j, cub->params->c);
		j++;
	}
	while (j < W_HEIGHT)
	{
		mlx_put_pixel(frame, *i, j, cub->params->f);
		j++;
	}
}

void	cube_it(t_cub *cub)
{
	int i;

	i = 0;
	mlx_image_t *frame;
	frame = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	while(i < W_WIDTH)
	{
		ceilingfloor(cub, frame, &i);
		if (i == W_WIDTH/2)
			raycast(cub, frame, &i);
		i++;
	}
	mlx_image_to_window(cub->mlx, frame, 0, 0);
}
