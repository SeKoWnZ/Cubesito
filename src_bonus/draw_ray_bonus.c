/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:01:51 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/20 19:18:05 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D_bonus.h>

int	get_pix(mlx_texture_t *wall, t_lil_ray *ray, int y_pos)
{
	int		pos;
	int		x_pos;
	int		y_tex;
	double	scale;

	scale = (double)wall->height / ray->w_size;
	x_pos = (int)(ray->pix * (wall->width - 1));
	y_tex = (int)(y_pos * scale);
	pos = (x_pos + y_tex * wall->width) * wall->bytes_per_pixel;
	if (pos < 0 || pos + 3 >= (int)(wall->width
		* wall->height * wall->bytes_per_pixel))
		return (0);
	return (wall->pixels[pos] << 24
		| wall->pixels[pos + 1] << 16
		| wall->pixels[pos + 2] << 8
		| wall->pixels[pos + 3]);
}

void	w_to_scr(mlx_texture_t *wall, t_lil_ray *ray, mlx_image_t *frame, int i)
{
	int	y_pos;
	int	y_max;
	int	y_min;

	if (ray->dis < 0.01)
		ray->dis = 0.01;
	ray->w_size = 800 / ray->dis;
	y_min = (W_HEIGHT - ray->w_size) / 2;
	y_max = (W_HEIGHT + ray->w_size) / 2;
	y_pos = y_min;
	while (y_pos < y_max)
	{
		if (y_pos >= 0 && y_pos < W_HEIGHT)
			mlx_put_pixel(frame, i, y_pos, get_pix(wall, ray, y_pos - y_min));
		y_pos++;
	}
}

void	draw_ray(t_cub *cub, t_lil_ray *ray, int r, int i)
{
	ray->pix = ray->cross[r] - (int)ray->cross[r];
	if (ray->wface == -2)
		w_to_scr(cub->params->so, ray, cub->frame, i);
	else if (ray->wface == 2)
		w_to_scr(cub->params->no, ray, cub->frame, i);
	else if (ray->wface == -1)
		w_to_scr(cub->params->ea, ray, cub->frame, i);
	else if (ray->wface == 1)
		w_to_scr(cub->params->we, ray, cub->frame, i);
}
