#include <cube3D.h>

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	rotate(t_cub *cub)
{
	static int frame_counter = 0;
	static int i;

	if (++frame_counter >= 10) 
	{
		frame_counter = 0;
		cub->params->img[i % 46]->enabled = false;
		i++;
		cub->params->img[i % 46]->enabled = true;
	}
}

void	animation_init(t_cub *cub)
{
	char	*s1 = ft_strdup("./textures/PNGS/0");
	char	*s11 = ft_strdup("./textures/PNGS/");
	char	*s3 = ft_strdup(".png");
	char	*s2;
	char	*s4;
	char	*s5;

	for (int i = 0; i < 46; i++)
	{
		s2 = ft_itoa(i + 1);
		if (i + 1 < 10)
			s4 = ft_strjoin(s1, s2);
		else
			s4 = ft_strjoin(s11, s2);
		s5 = ft_strjoin(s4, s3);
		cub->params->texture[i] = mlx_load_png(s5);
		if (!cub->params->texture[i])
			error();
		free(s2);
		free(s4);
		free(s5);
	}
	free(s1);
	free(s11);
	free(s3);

	// Convert texture to a displayable image
	for (int i = 0; i < 46; i++)
	{
		cub->params->img[i] = mlx_texture_to_image(cub->mlx, cub->params->texture[i]);
		mlx_resize_image(cub->params->img[i], 87, 100);
		if (!cub->params->img[i])
			error();
		if (mlx_image_to_window(cub->mlx, cub->params->img[i], W_WIDTH / 2 - 43, W_HEIGHT - 100) < 0)
			error();
		if (i == 0)
			cub->params->img[i]->enabled = true;
		else
			cub->params->img[i]->enabled = false;
	}
}