#include <cube3D.h>

int	valid_walls(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (params->map[j])
	{
		i = 0;
		while (params->map[j][i])
		{
			if (ft_strchr("WEN0S", params->map[j][i]))
			{
				if ((i == 0 || (params->map[j][i - 1] == ' '
					|| !params->map[j][i + 1] || params->map[j][i + 1] == ' ')))
					return(1);
				if ((j == 0 || (!params->map[j + 1]
					|| params->map[j - 1][i] == ' '
					|| params->map[j + 1][i] == ' ')))
					return(1);
			}
			i++;
		}
		j++;
	}
	return(0);
}

int	ok_char(char *map, int *lil_player, int *max_x)
{
	while (*map)
	{
		if (!ft_strchr(" 10NSEW", *map))
			return(1);
		if (ft_strchr("NSEW", *map))
			(*lil_player)++;
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
		return(1);
	if (square_map(params, map))
		return(1);
	if (valid_walls(params))
		return(1);
	return(0);
}
