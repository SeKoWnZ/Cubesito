/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:00:32 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/11 20:00:45 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

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

	cub->params->i_hud = mlx_texture_to_image(cub->mlx, cub->params->t_hud);
	if (!cub->params->i_hud)
		free_nano(E_MALLOC, cub);
	if (mlx_image_to_window(cub->mlx, cub->params->i_hud, -(cub->params->i_hud->width / 2) + (W_WIDTH / 5), -(cub->params->i_hud->height / 2) + (W_HEIGHT - W_HEIGHT / 5)) < 0)
		free_nano(E_MALLOC, cub);
	i = -1;
	while (++i < 46)
	{
		cub->params->img[i] = mlx_texture_to_image(cub->mlx, cub->params->texture[i]);
		mlx_resize_image(cub->params->img[i], 350 / 4.3, 400 / 4.3);
		if (!cub->params->img[i])
			free_nano(E_MALLOC, cub);
		if (mlx_image_to_window(cub->mlx, cub->params->img[i], -((350 / 4.3) / 2) + (W_WIDTH / 5), -((400 / 4.3) / 2) + (W_HEIGHT - W_HEIGHT / 5)) < 0)
			free_nano(E_MALLOC, cub);
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

	cub->params->t_hud = mlx_load_png("./textures/PNGS/HUD.png");
	if (!cub->params->t_hud)
		free_nano(E_MALLOC, cub);
	i = -1;
	while (++i < 46)
	{
		ft_bzero(str, 25);
		ft_memcpy(str, SOURCE, 16);
		tmp = ft_itoa(i + 1);
		if (!tmp)
			free_nano(E_MALLOC, cub);
		ft_strlcat(str, tmp, 25);
		free(tmp);
		ft_strlcat(str, SOURCE2, 25);
		cub->params->texture[i] = mlx_load_png(str);
		if (!cub->params->texture[i])
			free_nano(E_MALLOC, cub);
	}
	init_animation(cub);
}
