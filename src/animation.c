#include <cube3D.h>

void	animation_error(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->params->texture[++i])
		mlx_delete_texture(cub->params->texture[i]);
	i = -1;
	while (cub->params->texture[++i])
		mlx_delete_image(cub->mlx, cub->params->img[i]);
	error_exit(E_MALLOC, cub);
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

void	init_animation(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < 46)
	{
		cub->params->img[i] = mlx_texture_to_image(cub->mlx, cub->params->texture[i]);
		mlx_resize_image(cub->params->img[i], 87, 100);
		if (!cub->params->img[i])
			animation_error(cub);
		if (mlx_image_to_window(cub->mlx, cub->params->img[i], W_WIDTH / 2 - 43, W_HEIGHT - 100) < 0)
			animation_error(cub);
		if (i == 0)
			cub->params->img[i]->enabled = true;
		else
			cub->params->img[i]->enabled = false;
	}
}

void	animation_init(t_cub *cub)
{
	char	str[25];
	char 	*tmp;
	int		i;

	i = -1;
	while (++i < 46)
	{
		ft_bzero(str, 25);
		ft_memcpy(str, SOURCE, 16);
		tmp = ft_itoa(i + 1);
		if (!tmp)
			error_exit(E_MALLOC, cub);
		ft_strlcat(str, tmp, 25);
		free(tmp);
		ft_strlcat(str, SOURCE2, 25);
		cub->params->texture[i] = mlx_load_png(str);
		if (!cub->params->texture[i])
			animation_error(cub);
	}
	init_animation(cub);
}
