/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:26 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/11 20:05:27 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	init_rey(t_cub *cub, t_ray *rey, double ray_ang)
{
	rey->map = cub->params->map;
	rey->ang = ray_ang;
	rey->ang_b = rey->ang - cub->player->pang;
	rey->pos[x] = cub->player->pox;
	rey->pos[y] = cub->player->poy;
	rey->signx = 1;
	rey->signy = 1;
	if (rey->ang > (M_PI / 2) && rey->ang < (3 * M_PI / 2))
		rey->signx = -1;
	if (rey->ang < M_PI && rey->ang > 0)
	//if (rey->ang > rad_convertor(180) && rey->ang < rad_convertor(360))
		rey->signy = -1;
	rey->ray[x].step[x] = rey->signx;
	rey->ray[x].step[y] = rey->signy * fabs(tan(rey->ang));
	rey->ray[y].step[x] = rey->signx * fabs(1 / tan(rey->ang));
	rey->ray[y].step[y] = rey->signy;
}

void	raycast(t_cub *cub, double ray_ang, int *i)
{
	t_ray	rey;

	init_rey(cub, &rey, ray_ang);
	calculate_ray_x(&rey, cub->params);
	calculate_ray_y(&rey, cub->params);
	if (rey.ray[x].dis < rey.ray[y].dis)
	{
		rey.ray[x].dis = rey.ray[x].dis * fabs(cos(rey.ang_b));
		draw_ray(cub, &rey.ray[x], y, *i);
	}
	else
	{
		rey.ray[y].dis = rey.ray[y].dis * fabs(cos(rey.ang_b));
		draw_ray(cub, &rey.ray[y], x, *i);
	}
}
