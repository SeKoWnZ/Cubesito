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
	free(lil_cub->params);
}

int	error_free(char *error, t_cub *lil_cub, char **free_p)
{
	free_double_p(free_p);
	if (errno == 0)
	{
		ft_putstr_fd(error, 2);
		free_it(lil_cub);
	}
	else
	{
		perror(error);
		free_it(lil_cub);
	}
	exit(1);
}

int	error_exit(char *error, t_cub *lil_cub)
{
	if (errno == 0)
	{
		ft_putstr_fd(error, 2);
		free_it(lil_cub);
	}
	else
	{
		perror(error);
		free_it(lil_cub);
	}
	exit(1);
}
