/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cal_y_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:21 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/20 19:18:57 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D_bonus.h>

int	ray_collide_y(t_ray *rey, t_params *param)
{
	if ((int)rey->ray[Y].cross[X] >= param->max[X] || (int)rey->ray[Y].cross[Y]
		>= param->max[Y] || (int)rey->ray[Y].cross[X] <= 0
		|| (int)rey->ray[Y].cross[Y] <= 0)
		return (1);
	if (rey->signy == -1 && rey->map[(int)rey->ray[Y].cross[Y] - 1]
		[(int)rey->ray[Y].cross[X]] == '1')
		return (1);
	else if (rey->map[(int)rey->ray[Y].cross[Y]]
		[(int)rey->ray[Y].cross[X]] == '1')
		return (1);
	return (0);
}

void	first_step_y(t_ray *rey, int max)
{
	(void)max;
	if (rey->signy == 1)
		rey->ray[Y].cross[Y] = ((int)rey->pos[Y] + 1) - rey->pos[Y];
	else
		rey->ray[Y].cross[Y] = (int)rey->pos[Y] - rey->pos[Y];
	if (rey->ang == rad_convertor(90) || rey->ang == rad_convertor(270))
		rey->ray[Y].cross[X] = rey->pos[X];
	else
	{
		rey->ray[Y].cross[X] = rey->signx
			* (fabs(rey->ray[Y].cross[Y]) / fabs(tan(rey->ang)));
		rey->ray[Y].cross[X] = rey->ray[Y].cross[X] + rey->pos[X];
	}
	rey->ray[Y].cross[Y] = rey->ray[Y].cross[Y] + rey->pos[Y];
}

void	calculate_ray_y(t_ray *rey, t_params *param)
{
	first_step_y(rey, param->max[Y]);
	while (1)
	{
		if (ray_collide_y(rey, param))
			break ;
		rey->ray[Y].cross[X] += rey->ray[Y].step[X];
		rey->ray[Y].cross[Y] += rey->ray[Y].step[Y];
	}
	rey->ray[Y].wface = 2 * rey->signy;
	rey->ray[Y].dis = sqrt(pow(rey->ray[Y].cross[X] - rey->pos[X], 2)
			+ pow(rey->ray[Y].cross[Y] - rey->pos[Y], 2));
}
