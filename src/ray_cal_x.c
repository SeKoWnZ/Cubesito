/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cal_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:15 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/11 20:05:16 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	ray_collide_x(t_ray *rey, t_params *param)
{
	if ((int)rey->ray[x].cross[x] >= param->max[x] || (int)rey->ray[x].cross[y] >= param->max[y]
		|| (int)rey->ray[x].cross[x] <= 0 || (int)rey->ray[x].cross[y] <= 0)
		return (1);
	if (rey->signx == -1 && rey->map[(int)rey->ray[x].cross[y]][(int)rey->ray[x].cross[x] - 1] == '1')
		return (1);
	else if (rey->map[(int)rey->ray[x].cross[y]][(int)rey->ray[x].cross[x]] == '1')
		return (1);
	return (0);
}

void	first_step_x(t_ray *rey, int max)
{
	(void)max;
	if (rey->signx == 1)
		rey->ray[x].cross[x] = ((int)rey->pos[x] + 1) - rey->pos[x];
	else
		rey->ray[x].cross[x] = (int)rey->pos[x] - rey->pos[x];
	if (rey->ang == rad_convertor(0) || rey->ang == rad_convertor(180))
		rey->ray[x].cross[y] = rey->pos[y];
	else
	{
		rey->ray[x].cross[y] = rey->signy * (fabs(rey->ray[x].cross[x]) * fabs(tan(rey->ang)));
		rey->ray[x].cross[y] = rey->ray[x].cross[y] + rey->pos[y];
	}
	rey->ray[x].cross[x] = rey->ray[x].cross[x] + rey->pos[x];
}

void	calculate_ray_x(t_ray *rey, t_params *param)
{
	first_step_x(rey, param->max[x]);
	while (1)
	{
		if (ray_collide_x(rey, param))
			break ;
		rey->ray[x].cross[x] += rey->ray[x].step[x];
		rey->ray[x].cross[y] += rey->ray[x].step[y];
	}
	rey->ray[x].wface = 1 * rey->signx;
	rey->ray[x].dis = sqrt(pow(rey->ray[x].cross[x] - rey->pos[x], 2) + pow(rey->ray[x].cross[y] - rey->pos[y], 2));
}
