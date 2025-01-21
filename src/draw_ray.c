#include <cube3D.h>

void	paint_ray(mlx_texture_t *wall, float pix)
{
	wall.
}

void	draw_ray(t_cub *cub, t_lil_ray *ray, mlx_image_t *frame, int r)
{
	if (ray->wface == -2)
		paint_ray(cub->params->so, ray->cross[r] - (int)ray->cross[r]);
	else if (ray->wface == 2)
		paint_ray(cub->params->no, ray->cross[r] - (int)ray->cross[r]);
	else if (ray->wface == -1)
		paint_ray(cub->params->ea, ray->cross[r] - (int)ray->cross[r]);
	else if (ray->wface == 1)
		paint_ray(cub->params->we, ray->cross[r] - (int)ray->cross[r]);
}
