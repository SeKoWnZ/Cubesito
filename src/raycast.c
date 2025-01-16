#include <cube3D.h>

void	first_step(t_ray *rey, float *r_pos, int r)
{
	if (r == x)
	{
		if (rey->signx == 1)
			rey->ray[x].cross[x] = ((int)r_pos[x] + 1) - r_pos[x];
		else
			rey->ray[x].cross[x] = (int)r_pos[x] - r_pos[x];
		rey->ray[x].cross[y] = rey->ray[x].cross[x] / tan(rey->ang);
		rey->ray[x].cross[y] = rey->ray[x].cross[y] + r_pos[y];
	}
	else
	{
		if (rey->signy == 1)
			rey->ray[y].cross[y] = ((int)r_pos[y] + 1) - r_pos[y];
		else
			rey->ray[y].cross[y] = (int)r_pos[y] - r_pos[y];
		rey->ray[y].cross[x] = rey->ray[y].cross[y] * tan(rey->ang);
		rey->ray[y].cross[x] = rey->ray[y].cross[x] + r_pos[x];
	}
}

int	ray_collide(t_ray *rey, t_params *param, int r)
{
	printf("RAY (y=%f, x=%f)\n", rey->ray[r].cross[y], rey->ray[r].cross[x]);
	if (rey->ray[r].cross[x] > param->max[x] || rey->ray[r].cross[y] > param->max[y] || rey->ray[r].cross[x] < 0 || rey->ray[r].cross[y] < 0)
		return (1);
	if (rey->map[(int)rey->ray[r].cross[y]][(int)rey->ray[r].cross[x]] == '1')
		return (1);
	return (0);
	//CROSS DEL RAYO R ESTA OCUPADO POR UN MURO?? O YA ESTA FUERA DEL MAPA??
}

void	calculate_ray(t_ray *rey, float *r_pos, t_params *param, int r)
{
	first_step(rey, r_pos, r);
	while (1)
	{
		if (ray_collide(rey, param, r))
			break ;
	rey->ray[r].cross[x] += rey->ray[r].step[x];
	rey->ray[r].cross[y] += rey->ray[r].step[y];
	}
}
void	raycast(t_cub *cub, mlx_image_t *frame, int *i)
{
	t_ray	rey;

	(void)frame;
	(void)i;
	rey.map = cub->params->map;
	rey.ang = cub->player->pang;
	rey.pos[x] = cub->player->pox;
	rey.pos[y] = cub->player->poy;
	rey.signx = 1;
	if (rey.ang > rad_convertor(90) && rey.ang < rad_convertor(270))
		rey.signx = -1;
	rey.signy = 1;
	if (rey.ang > rad_convertor(180) && rey.ang < rad_convertor(360))
		rey.signy = -1;
	rey.ray[x].step[x] = rey.signx;
	rey.ray[x].step[y] = rey.ray[y].cross[y] * tan(rey.ang);
	rey.ray[y].step[x] = rey.ray[x].cross[y] / tan(rey.ang);
	rey.ray[y].step[y] = rey.signy;
	printf("SING X: %i\nSING Y: %i\n", rey.signx, rey.signy);
	calculate_ray(&rey, rey.pos, cub->params, x);
	calculate_ray(&rey, rey.pos, cub->params, y);
	printf("RAY Y (y=%f, x=%f)\nRAY X (y=%f, x=%f)\n", rey.ray[y].cross[y], rey.ray[y].cross[x], rey.ray[x].cross[y], rey.ray[x].cross[x]);
	// if (rey.ray[x].dis < rey.ray[y].dis)
	// {

	// }
}
