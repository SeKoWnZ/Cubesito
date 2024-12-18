#include <cube3D.h>
int	ok_char(char *map, int *lil_player, int *max_x)
{
	while (*map)
	{
		if (!ft_strchr(" 10NSEW", *map))
			return(1);
		if (!ft_strchr("NSEW", *map))
			lil_player++;
		(*max_x)++;
		map++;
	}
	return(0);
}
int	size_n_char(t_params *params, char **map)
{
	int max_x;
	int	lil_player;

	lil_player = 0;
	while (*map)
	{
		max_x = 0;
		if (ok_char(*map, &lil_player, &max_x))
			return(1);
		map++;
		params->max[y]++;
		if (max_x > params->max[x])
			params->max[x] = max_x;
	}
	if (lil_player != 1)
		return(1);
	return(0);
}

int	 valid_map(t_params *params, char **map)
{
	if (size_n_char(params, map))
		return(0);
	//añadir espacios
	//guardar
	return(0);
}
