#include <cube3D.h>

void	firt_step(t_ray *rey, float *r_pos, int r)
{
	if (r == x)
	{
		if (rey->signx == 1)
			rey->x_ray.cross[x] = ((int)r_pos[x] + 1) - r_pos[x];
		else
			rey->x_ray.cross[x] = (int)r_pos[x] - r_pos[x];
		rey->x_ray.cross[y] = rey->x_ray.cross[x] / tan(rey->ang);
		rey->x_ray.cross[y] = rey->x_ray.cross[y] + r_pos[y];
	}
	else
	{
		if (rey->signy == 1)
			rey->y_ray.cross[y] = ((int)r_pos[y] + 1) - r_pos[y];
		else
			rey->y_ray.cross[y] = (int)r_pos[y] - r_pos[y];
		rey->y_ray.cross[x] = rey->y_ray.cross[y] * tan(rey->ang);
		rey->y_ray.cross[x] = rey->y_ray.cross[x] + r_pos[x];
	}
}

int	ray_collide(t_ray *rey,  )
{

}

void	calculate_ray(t_ray *rey, float *r_pos, int r)
{
	first_step(rey, r_pos, r);
	while (1)
	{
		ray_collide(rey, r)
			//BREAK;
	}
	
}
void	raycast(t_cub *cub, mlx_image_t *frame, int *i)
{
	t_ray	rey;

	(void)frame;
	(void)i;
	rey.map = cub->map;
	rey.ang = cub->player->pang;
	rey.pos[x] = cub->player->pox;
	rey.pos[y] = cub->player->poy;
	rey.signx = 1;
	if (rey.ang > rad_convertor(90) && rey.ang < rad_convertor(270))
		rey.signx = -1;
	rey.signy = 1;
	if (rey.ang > rad_convertor(180) && rey.ang < rad_convertor(360))
		rey.signy = -1;
	printf("SING X: %i\nSING Y: %i\n", rey.signx, rey.signy);
	calculate_ray(&rey, rey.pos, x);
	calculate_ray(&rey, rey.pos, y);
	if (rey.x_ray.dis < rey.y_ray.dis)
	{

	}
}
