#include <cube3D.h>

void	free_it(t_cub *lil_cub)
{
	if (lil_cub->map)
		free(lil_cub->map);
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
