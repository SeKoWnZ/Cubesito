/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:29 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/20 19:19:06 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D_bonus.h>

int	square_map(t_params *params, char **map)
{
	int		i;
	int		extra;

	i = -1;
	params->map = ft_calloc(params->max[Y] + 1, sizeof(char *));
	if (!params->map)
		return (1);
	while (++i < params->max[Y])
	{
		params->map[i] = ft_calloc(params->max[X] + 1, sizeof(char));
		if (!params->map[i])
			return (1);
		extra = ft_strlen(map[i]);
		ft_memcpy(params->map[i], map[i], extra);
		if (extra < params->max[X])
			ft_memset(&params->map[i][extra], ' ', params->max[X] - extra);
	}
	return (0);
}
