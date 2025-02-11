/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:02:10 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/11 20:02:14 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	free_double_p(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	free_it(t_cub *lil_cub)
{
	if (lil_cub->map)
		free(lil_cub->map);
	if (lil_cub->params->map)
		free_double_p(lil_cub->params->map);
	if (lil_cub->params->no)
		mlx_delete_texture(lil_cub->params->no);
	if (lil_cub->params->so)
		mlx_delete_texture(lil_cub->params->so);
	if (lil_cub->params->ea)
		mlx_delete_texture(lil_cub->params->ea);
	if (lil_cub->params->we)
		mlx_delete_texture(lil_cub->params->we);
	if (lil_cub->mlx)
		mlx_terminate(lil_cub->mlx);
	free(lil_cub->params);
	free(lil_cub->player);
}
void	free_nano(char *error, t_cub *cub)
{
	int	i;

	if (cub->params->t_hud)
		mlx_delete_texture(cub->params->t_hud);
	i = -1;
	while (++i < 46)
		mlx_delete_texture(cub->params->texture[i]);
	error_exit(error, cub);
}

int	error_free(char *error, t_cub *lil_cub, char **free_p)
{
	free_double_p(free_p);
	free_it(lil_cub);
	if (error != NULL)
	{
		if (errno == 0)
			ft_putstr_fd(error, 2);
		else
			perror(error);
		exit(1);
	}
	return (0);
}

int	error_exit(char *error, t_cub *lil_cub)
{
	free_it(lil_cub);
	if (error != NULL)
	{
		if (errno == 0)
			ft_putstr_fd(error, 2);
		else
			perror(error);
		exit(1);
	}
	return (0);
}
