#include <cube3D.h>

void	first_step(t_ray *rey, float *r_pos, int r)
{
	if (r == x)
	{
		if (rey->signx == 1)
			rey->ray[x].cross[x] = ((int)r_pos[x] + 1) - r_pos[x];
		else
			rey->ray[x].cross[x] = (int)r_pos[x] - r_pos[x];
		if (rey->ang == rad_convertor(0) || rey->ang == rad_convertor(180))
			rey->ray[x].cross[y] = r_pos[y];
		else
		{
			rey->ray[x].cross[y] = rey->ray[x].cross[x] / tan(rey->ang);
			rey->ray[x].cross[y] = rey->ray[x].cross[y] + r_pos[y];
		}
		rey->ray[x].cross[x] = rey->ray[x].cross[x] + r_pos[x];
	}
	else
	{
		if (rey->signy == 1)
			rey->ray[y].cross[y] = ((int)r_pos[y] + 1) - r_pos[y];
		else
			rey->ray[y].cross[y] = (int)r_pos[y] - r_pos[y];
		if (rey->ang == rad_convertor(90) || rey->ang == rad_convertor(270))
			rey->ray[y].cross[x] = r_pos[x];
		else
		{
			rey->ray[y].cross[x] = rey->ray[y].cross[y] * tan(rey->ang);
			rey->ray[y].cross[x] = rey->ray[y].cross[x] + r_pos[x];
		}
			rey->ray[y].cross[y] = rey->ray[y].cross[y] + r_pos[y];
	}
}

int	ray_collide(t_ray *rey, t_params *param, int r)
{
	printf("RAY (y=%f, x=%f)\n", rey->ray[r].cross[y], rey->ray[r].cross[x]);
	if (rey->ray[r].cross[x] >= param->max[x] || rey->ray[r].cross[y] >= param->max[y] || rey->ray[r].cross[x] < 0 || rey->ray[r].cross[y] < 0)
		return (1);
	if (rey->map[(int)rey->ray[r].cross[y]][(int)rey->ray[r].cross[x]] == '1')
		return (1);
	return (0);
	//CROSS DEL RAYO R ESTA OCUPADO POR UN MURO?? O YA ESTA FUERA DEL MAPA??
}

void	calculate_ray(t_ray *rey, float *r_pos, t_params *param, int r)
{
	first_step(rey, r_pos, r);
	printf("PLAYER Y :%f | PLAYER X :%f\n", rey->pos[y], rey->pos[x]);
	printf("CROSS Y :%f | CROSS X :%f\n", rey->ray[r].cross[y], rey->ray[r].cross[x]);
	while (1)
	{
		if (ray_collide(rey, param, r))
			break ;
	rey->ray[r].cross[x] += rey->ray[r].step[x];
	rey->ray[r].cross[y] += rey->ray[r].step[y];
	}
	if (r == x)
		rey->ray[r].wface = 1 * rey->signx;
	else
		rey->ray[r].wface = 2 * rey->signy;
	rey->ray[r].dis = sqrt(pow(rey->ray[r].cross[x] - rey->pos[x], 2) + pow(rey->ray[r].cross[y] - rey->pos[y], 2));
	//coll.distance = coll.raylen * cos(ray->deltaang);
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
	rey.ray[y].step[y] = rey.signy;
	rey.ray[x].step[y] = rey.signy * tan(rey.ang);
	rey.ray[y].step[x] = rey.signx / tan(rey.ang);
	if (rey.ang == rad_convertor(0) || rey.ang == rad_convertor(180))
	{
		rey.ray[x].step[y] = 0;
		rey.ray[y].dis = __FLT_MAX__;
	}
	if (rey.ang == rad_convertor(90) || rey.ang == rad_convertor(270))
	{
		rey.ray[y].step[x] = 0;
		rey.ray[x].dis = __FLT_MAX__;
	}
	printf("SING X: %i\nSING Y: %i\n", rey.signx, rey.signy);
	if (rey.ray[x].dis != __FLT_MAX__)
		calculate_ray(&rey, rey.pos, cub->params, x);
	if (rey.ray[y].dis != __FLT_MAX__)
		calculate_ray(&rey, rey.pos, cub->params, y);
	printf("RAY Y (y=%f, x=%f)\nRAY X (y=%f, x=%f)\n", rey.ray[y].cross[y], rey.ray[y].cross[x], rey.ray[x].cross[y], rey.ray[x].cross[x]);
	if (rey.ray[x].dis < rey.ray[y].dis)
		draw_ray(cub, &rey.ray[x], frame, y);
	else
		draw_ray(cub, &rey.ray[y], frame, x);
}
