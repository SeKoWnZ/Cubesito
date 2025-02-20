/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:03:04 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/20 19:18:30 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D_bonus.h>

int	two_hi_n(char *map)
{
	int	i;
	int	in_map;

	i = -1;
	in_map = 0;
	while (map[++i])
	{
		if (map[i] == '\n' && (map[i + 1] == ' '
				|| map[i + 1] == '0' || map[i + 1] == '1'))
			in_map = 1;
		if (in_map == 1 && map[i] == '\n' && (map[i + 1] == '\n'))
			return (1);
	}
	return (0);
}

int	check_all_in(t_params *params)
{
	if (!params->no || !params->so || !params->ea || !params->we)
		return (1);
	if (params->c == -1 || params->f == -1)
		return (1);
	return (0);
}

int	save_texture(mlx_texture_t **orientation, char *param)
{
	while (*param && *param == ' ')
		param++;
	if (*param)
	{
		if (!*orientation)
		{
			*orientation = mlx_load_png(param);
			if (!*orientation)
				return (1);
			return (0);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

int	save_params(t_cub *lil_cub, char **params)
{
	if (**params == 'N' && *(*params + 1) == 'O')
		if (save_texture(&lil_cub->params->no, *params + 2))
			return (1);
	if (**params == 'S' && *(*params + 1) == 'O')
		if (save_texture(&lil_cub->params->so, *params + 2))
			return (1);
	if (**params == 'E' && *(*params + 1) == 'A')
		if (save_texture(&lil_cub->params->ea, *params + 2))
			return (1);
	if (**params == 'W' && *(*params + 1) == 'E')
		if (save_texture(&lil_cub->params->we, *params + 2))
			return (1);
	if (**params == 'C')
		if (save_color(&lil_cub->params->c, *params + 1))
			return (1);
	if (**params == 'F')
		if (save_color(&lil_cub->params->f, *params + 1))
			return (1);
	return (0);
}

int	check_n_save(t_cub *lil_cub, char **params, char **free_p)
{
	while (params && !ft_strchr(" 10", **params))
	{
		if (save_params(lil_cub, params))
			error_free(E_PARAM, lil_cub, free_p);
		params++;
	}
	if (check_all_in(lil_cub->params))
		error_free(E_MISS, lil_cub, free_p);
	if (valid_map(lil_cub->params, params))
		error_free(E_MAP, lil_cub, free_p);
	return (0);
}
