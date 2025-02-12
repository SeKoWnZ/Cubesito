/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:29 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/12 16:51:08 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	square_map(t_params *params, char **map)
{
	int		i;
	int		extra;

	i = -1;
	params->map = ft_calloc(params->max[y] + 1, sizeof(char *));
	if (!params->map)
		return (1);
	while (++i < params->max[y])
	{
		params->map[i] = ft_calloc(params->max[x] + 1, sizeof(char));
		if (!params->map[i])
			return (1);
		extra = ft_strlen(map[i]);
		ft_memcpy(params->map[i], map[i], extra);
		if (extra < params->max[x])
			ft_memset(&params->map[i][extra], ' ', params->max[x] - extra);
	}
	return (0);
}
