/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:26 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/12 17:36:53 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	init_rey(t_cub *cub, t_ray *rey, double ray_ang)
{
	rey->map = cub->params->map;
	rey->ang = ray_ang;
	rey->ang_b = rey->ang - cub->player->pang;
	rey->pos[X] = cub->player->pox;
	rey->pos[Y] = cub->player->poy;
	rey->signx = 1;
	rey->signy = 1;
	if (rey->ang > (M_PI / 2) && rey->ang < (3 * M_PI / 2))
		rey->signx = -1;
	if (rey->ang < M_PI && rey->ang > 0)
		rey->signy = -1;
	rey->ray[X].step[X] = rey->signx;
	rey->ray[X].step[Y] = rey->signy * fabs(tan(rey->ang));
	rey->ray[Y].step[X] = rey->signx * fabs(1 / tan(rey->ang));
	rey->ray[Y].step[Y] = rey->signy;
}

void	raycast(t_cub *cub, double ray_ang, int *i)
{
	t_ray	rey;

	init_rey(cub, &rey, ray_ang);
	calculate_ray_x(&rey, cub->params);
	calculate_ray_y(&rey, cub->params);
	if (rey.ray[X].dis < rey.ray[Y].dis)
	{
		rey.ray[X].dis = rey.ray[X].dis * fabs(cos(rey.ang_b));
		draw_ray(cub, &rey.ray[X], Y, *i);
	}
	else
	{
		rey.ray[Y].dis = rey.ray[Y].dis * fabs(cos(rey.ang_b));
		draw_ray(cub, &rey.ray[Y], X, *i);
	}
}
