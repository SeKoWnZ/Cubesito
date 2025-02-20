/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cal_x_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:15 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/20 19:18:51 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D_bonus.h>

int	ray_collide_x(t_ray *rey, t_params *param)
{
	if ((int)rey->ray[X].cross[X] >= param->max[X]
		|| (int)rey->ray[X].cross[Y] >= param->max[Y]
		|| (int)rey->ray[X].cross[X] <= 0 || (int)rey->ray[X].cross[Y] <= 0)
		return (1);
	if (rey->signx == -1 && rey->map[(int)rey->ray[X].cross[Y]]
		[(int)rey->ray[X].cross[X] - 1] == '1')
		return (1);
	else if (rey->map[(int)rey->ray[X].cross[Y]]
		[(int)rey->ray[X].cross[X]] == '1')
		return (1);
	return (0);
}

void	first_step_x(t_ray *rey, int max)
{
	(void)max;
	if (rey->signx == 1)
		rey->ray[X].cross[X] = ((int)rey->pos[X] + 1) - rey->pos[X];
	else
		rey->ray[X].cross[X] = (int)rey->pos[X] - rey->pos[X];
	if (rey->ang == rad_convertor(0) || rey->ang == rad_convertor(180))
		rey->ray[X].cross[Y] = rey->pos[Y];
	else
	{
		rey->ray[X].cross[Y] = rey->signy * (fabs(rey->ray[X].cross[X])
				* fabs(tan(rey->ang)));
		rey->ray[X].cross[Y] = rey->ray[X].cross[Y] + rey->pos[Y];
	}
	rey->ray[X].cross[X] = rey->ray[X].cross[X] + rey->pos[X];
}

void	calculate_ray_x(t_ray *rey, t_params *param)
{
	first_step_x(rey, param->max[X]);
	while (1)
	{
		if (ray_collide_x(rey, param))
			break ;
		rey->ray[X].cross[X] += rey->ray[X].step[X];
		rey->ray[X].cross[Y] += rey->ray[X].step[Y];
	}
	rey->ray[X].wface = 1 * rey->signx;
	rey->ray[X].dis = sqrt(pow(rey->ray[X].cross[X] - rey->pos[X], 2)
			+ pow(rey->ray[X].cross[Y] - rey->pos[Y], 2));
}
