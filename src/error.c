#include <cube3D.h>

void	free_it(t_cub *cub)
{
	free(cub);
}

int	error_exit(char *error, t_cub *cub)
{
	if (errno == 0)
	{
		ft_putstr_fd(error, 2);
		free_it(cub);
	}
	else
	{
		perror(error);
		free_it(cub);
	}
	exit(1);
}
