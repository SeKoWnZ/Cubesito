/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_it_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:01:03 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/20 19:17:50 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D_bonus.h>

void	ceilingfloor(t_cub *cub, mlx_image_t *frame, int *i)
{
	int	j;

	j = 0;
	while (j < W_HEIGHT / 2)
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
	int		i;
	double	ang_step;
	double	ray_ang;

	i = 0;
	ang_step = rad_convertor((FOV + 0.0) / (W_WIDTH + 0.0));
	if (cub->player->pang + rad_convertor(FOV / 2) > 2 * M_PI)
		ray_ang = cub->player->pang + rad_convertor(FOV / 2 - 360);
	else
		ray_ang = cub->player->pang + rad_convertor(FOV / 2);
	while (i < W_WIDTH)
	{
		ceilingfloor(cub, cub->frame, &i);
		raycast(cub, ray_ang, &i);
		if (ray_ang - ang_step < 0)
			ray_ang = ray_ang + (2 * M_PI) - ang_step;
		else
			ray_ang = ray_ang - ang_step;
		i++;
	}
}
