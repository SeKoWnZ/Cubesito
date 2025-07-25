/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:02:26 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:32 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_cube(t_cub *lil_cub)
{
	lil_cub->map = NULL;
	lil_cub->mlx = NULL;
	lil_cub->params = ft_calloc(1, sizeof(t_params));
	if (!lil_cub->params)
		error_exit(E_MALLOC, lil_cub);
	lil_cub->player = ft_calloc(1, sizeof(t_player));
	if (!lil_cub->player)
		error_exit(E_MALLOC, lil_cub);
	lil_cub->params->no = NULL;
	lil_cub->params->so = NULL;
	lil_cub->params->ea = NULL;
	lil_cub->params->we = NULL;
	lil_cub->params->map = NULL;
	lil_cub->params->c = -1;
	lil_cub->params->f = -1;
}
