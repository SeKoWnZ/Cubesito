#include "cube3D.h"

int	init_cube(t_cub *lil_cub)
{
	lil_cub = ft_calloc(1, sizeof(t_cub));
	if (!lil_cub)
		error_exit(E_MALLOC, NULL);
	lil_cub->map = NULL;
	return (0);
}
