#include <cube3D.h>

int	square_map(t_params *params, char **map)
{
	int		i;
	int		extra;

	i = -1;
	params->map = calloc(params->max[y], sizeof(char *));
	if (!params->map)
		return(1);
	while (++i < params->max[y])
	{
		params->map[i] = calloc(params->max[x], sizeof(char));
			if (!params->map[i])
				return(1);
		extra = ft_strlen(map[i]);
		ft_memcpy(params->map[i], map[i], extra);
		if (extra < params->max[x])
			ft_memset(&params->map[i][extra], ' ', params->max[x] - extra);
	}
	return(0);
}
