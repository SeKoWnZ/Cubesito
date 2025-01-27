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
			rey->ray[x].cross[y] = rey->signy * (fabs(rey->ray[x].cross[x]) / fabs(tan(rey->t_ang)));
			if (rey->ray[x].cross[y] <= 0 || rey->ray[x].cross[y] > 10)
				rey->ray[x].cross[y] = r_pos[y];
			else
				rey->ray[x].cross[y] = rey->ray[x].cross[y] + r_pos[y];
		}
		rey->ray[x].cross[x] = rey->ray[x].cross[x] + r_pos[x];
		printf("FSTEP X = %f, %f\n", rey->ray[x].cross[x], rey->ray[x].cross[y]);
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
			rey->ray[y].cross[x] = rey->signx * (fabs(rey->ray[y].cross[y]) * fabs(tan(rey->t_ang)));
			if (rey->ray[y].cross[x] <= 0 || rey->ray[y].cross[x] > 10)
				rey->ray[y].cross[x] = r_pos[x];
			else
				rey->ray[y].cross[x] = rey->ray[y].cross[x] + r_pos[x];
		}
		rey->ray[y].cross[y] = rey->ray[y].cross[y] + r_pos[y];
		printf("FSTEP Y = %f, %f\n", rey->ray[y].cross[x], rey->ray[y].cross[y]);
	}
}

int	ray_collide(t_ray *rey, t_params *param, int r)
{
	if ((int)rey->ray[r].cross[x] >= param->max[x] || (int)rey->ray[r].cross[y] >= param->max[y] || (int)rey->ray[r].cross[x] <= 0 || (int)rey->ray[r].cross[y] <= 0)
		return (1);
	if (r == x)
	{
		if (rey->signx == -1 && rey->map[(int)rey->ray[r].cross[y]][(int)rey->ray[r].cross[x] - 1] == '1')
			return (1);
		else if (rey->map[(int)rey->ray[r].cross[y]][(int)rey->ray[r].cross[x]] == '1')
			return (1);
	}
	else
	{
		if (rey->signy == -1 && rey->map[(int)rey->ray[r].cross[y] - 1][(int)rey->ray[r].cross[x]] == '1')
			return (1);
		else if (rey->map[(int)rey->ray[r].cross[y]][(int)rey->ray[r].cross[x]] == '1')
			return (1);
	}
	return (0);
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
	printf("R = %d CROSSX = %f | CORSY = %f\n",r, rey->ray[r].cross[x], rey->ray[r].cross[y]);
	if (r == x)
		rey->ray[r].wface = 1 * rey->signx;
	else
		rey->ray[r].wface = 2 * rey->signy;
	rey->ray[r].dis = sqrt(pow(rey->ray[r].cross[x] - rey->pos[x], 2) + pow(rey->ray[r].cross[y] - rey->pos[y], 2));
	//coll.distance = coll.raylen * cos(ray->deltaang);
}

void	raycast(t_cub *cub, double ray_ang, int *i)
{
	t_ray	rey;

	rey.map = cub->params->map;
	rey.ang = ray_ang;
	printf("RAY_ANG raycast = %f\n", rey.ang);
	rey.pos[x] = cub->player->pox;
	rey.pos[y] = cub->player->poy;
	printf("Starting ray POS = %f, %f\n", rey.pos[x], rey.pos[y]);
	rey.signx = 1;
	if (rey.ang > rad_convertor(90) && rey.ang < rad_convertor(270))
		rey.signx = -1;
	rey.signy = 1;
	if (rey.ang > rad_convertor(180) && rey.ang < rad_convertor(360))
		rey.signy = -1;
	printf("Ray signs = %d, %d\n", rey.signx, rey.signy);
	rey.t_ang = fabs(cub->player->pang - ray_ang);
	printf("RAY T_ANG before steps = %f\n", rey.t_ang);
	rey.ray[x].step[x] = rey.signx;
	rey.ray[x].step[y] = rey.signy * fabs(1 * tan(rey.t_ang));
	rey.ray[y].step[x] = rey.signx * fabs(1 / tan(rey.t_ang));
	rey.ray[y].step[y] = rey.signy;
	printf("STEPS X = %f, %f\nSTEPS Y = %f, %f\n", rey.ray[x].step[x], rey.ray[x].step[y], rey.ray[y].step[x], rey.ray[y].step[y]);
	// if (rey.ang == rad_convertor(0) || rey.ang == rad_convertor(180))
	// {
	// 	rey.ray[x].step[y] = 0;
	// 	rey.ray[y].dis = __FLT_MAX__;
	// }
	// if (rey.ang == rad_convertor(90) || rey.ang == rad_convertor(270))
	// {
	// 	rey.ray[y].step[x] = 0;
	// 	rey.ray[x].dis = __FLT_MAX__;
	// }
	//if (rey.ray[x].dis != __FLT_MAX__)
	calculate_ray(&rey, rey.pos, cub->params, x);
	//if (rey.ray[y].dis != __FLT_MAX__)
	calculate_ray(&rey, rey.pos, cub->params, y);
	printf("X RAY DIS = %f\n Y RAY DIS = %f\n", rey.ray[x].dis, rey.ray[y].dis);
	if (rey.ray[x].dis < rey.ray[y].dis)
		draw_ray(cub, &rey.ray[x], y, *i);
	else
		draw_ray(cub, &rey.ray[y], x, *i);
}
