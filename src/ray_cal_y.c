#include <cube3D.h>

int	ray_collide_y(t_ray *rey, t_params *param)
{
	if ((int)rey->ray[y].cross[x] >= param->max[x] || (int)rey->ray[y].cross[y] >= param->max[y] || (int)rey->ray[y].cross[x] <= 0 || (int)rey->ray[y].cross[y] <= 0)
		return (1);
	if (rey->signy == -1 && rey->map[(int)rey->ray[y].cross[y] - 1][(int)rey->ray[y].cross[x]] == '1')
		return (1);
	else if (rey->map[(int)rey->ray[y].cross[y]][(int)rey->ray[y].cross[x]] == '1')
		return (1);
	return (0);
}

void	first_step_y(t_ray *rey)
{
	if (rey->signy == 1)
		rey->ray[y].cross[y] = ((int)rey->pos[y] + 1) - rey->pos[y];
	else
		rey->ray[y].cross[y] = (int)rey->pos[y] - rey->pos[y];
	if (rey->ang == rad_convertor(90) || rey->ang == rad_convertor(270))
		rey->ray[y].cross[x] = rey->pos[x];
	else
	{
		rey->ray[y].cross[x] = rey->signx * ((rey->ray[y].cross[y]) / fabs(tan(rey->ang)));
		printf("RAY Y CROSS X = %f\n", rey->ray[y].cross[x]);
		if (rey->ray[y].cross[x] < 0 || rey->ray[y].cross[x] > 10)
			rey->ray[y].cross[x] = rey->pos[x];
		else
			rey->ray[y].cross[x] = rey->ray[y].cross[x] + rey->pos[x];
	}
	rey->ray[y].cross[y] = rey->ray[y].cross[y] + rey->pos[y];
}

void	calculate_ray_y(t_ray *rey, t_params *param)
{
	first_step_y(rey);
	while (1)
	{
		if (ray_collide_y(rey, param))
			break ;
		rey->ray[y].cross[x] += rey->ray[y].step[x];
		rey->ray[y].cross[y] += rey->ray[y].step[y];
	}
	rey->ray[y].wface = 2 * rey->signy;
	rey->ray[y].dis = sqrt(pow(rey->ray[y].cross[x] - rey->pos[x], 2) + pow(rey->ray[y].cross[y] - rey->pos[y], 2));
	rey->ray[y].dis = rey->ray[y].dis * (fabs)(cos(rey->ang_b));
}
