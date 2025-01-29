#include <cube3D.h>

int	get_pix(mlx_texture_t *wall,t_lil_ray *ray, int y_pos)
{
	int		pos;
	int		x_pos;
	double	scale;
	
	scale = wall->height / ray->w_size;
	x_pos = ray->pix * wall->width;
	y_pos = (int)(y_pos * scale) * wall->width;
	pos = (x_pos + y_pos) * wall->bytes_per_pixel;
	if (pos < 0 || pos + 3 > (int)(wall->width * wall->height * 4))
		return(0);
	return ((wall->pixels[pos] << 24 | wall->pixels[pos + 1] << 16 | wall->pixels[pos + 2] << 8 | wall->pixels[pos + 3]));
}

void	wall_to_screen(mlx_texture_t *wall,t_lil_ray *ray, mlx_image_t *frame, int i)
{
	int	y_pos;
	int	y_max;

	ray->w_size = wall->height / ray->dis;
	y_pos = (W_HEIGHT - ray->w_size) / 2;
	y_max = (W_HEIGHT + ray->w_size) / 2;
	while (y_pos < y_max)
	{
		if (y_pos > 0 && y_pos < W_HEIGHT)
			mlx_put_pixel(frame, i, y_pos, get_pix(wall, ray, (y_pos - (W_HEIGHT - ray->w_size) / 2)));
		y_pos++;
	}
}

void	draw_ray(t_cub *cub, t_lil_ray *ray, int r, int i)
{
	ray->pix = ray->cross[r] - (int)ray->cross[r];
	if (ray->wface == -2)
		wall_to_screen(cub->params->so, ray, cub->frame, i);
	else if (ray->wface == 2)
		wall_to_screen(cub->params->no, ray, cub->frame, i);
	else if (ray->wface == -1)
		wall_to_screen(cub->params->ea, ray, cub->frame, i);
	else if (ray->wface == 1)
		wall_to_screen(cub->params->we, ray, cub->frame, i);
}
