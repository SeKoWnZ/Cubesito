#include <cube3D.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	save_color(int *c, char *color)
{
	char **nums;

	if (*c != -1)
		return (1);
	while (*color && *color == ' ')
	color++;
	int i = 0;
	int comita = 0;
	while (color[i])
	{
		if (!ft_strchr(",1234567890", color[i]))
			return(1);
		else if (color[i] == ',')
			comita++;
		i++;
	}
	if (comita != 2)
		return(1);
	nums = ft_split(color, ',');
	if (!nums)
		return(1);
	i = 0;
	while (nums[i])
		i++;
	if (i != 3)
		return (1);
	int rgb[3];
	while (--i > 0)
	{
		if (!ft_atoitoa_cmp(nums[i]))
		{
			rgb[i] = ft_atoi(nums[i]);
			if (rgb[i] < 0 || rgb[i] > 255)
				return(free_double_p(nums), 1);
		}
		else
			return(free_double_p(nums), 1);
	}
	free_double_p(nums);
	*c = get_rgba(rgb[0], rgb[1], rgb[3], 255);
	return(0);
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
				return(1);
			return(0);
		}
		else
			return(1);
	}
	else
		return(1);
	return(0);
}

int	check_all_in(t_cub *lil_cub, char **params)
{
	while (params && !ft_strchr(" 10", **params))
	{
		ft_putstr_fd("parara\n", 2);
		if (**params == 'N' && *(*params + 1) == 'O')
			if (save_texture(&lil_cub->params->no, *params + 2))
				return(1);
		if (**params == 'S' && *(*params + 1) == 'O')
			if (save_texture(&lil_cub->params->so, *params + 2))
				return(1);
		if (**params == 'E' && *(*params + 1) == 'A')
			if (save_texture(&lil_cub->params->ea, *params + 2))
				return(1);
		if (**params == 'W' && *(*params + 1) == 'E')
			if (save_texture(&lil_cub->params->we, *params + 2))
				return(1);
		if (**params == 'C')
			if (save_color(&lil_cub->params->c, *params + 1))
				return(1);
		if (**params == 'F')
			if (save_color(&lil_cub->params->f, *params + 1))
				return(1);
		params++;
	}
	return(0);
}

void	check_params(t_cub *lil_cub)
{
	char **params;

	params = ft_split(lil_cub->map, '\n');
	if (check_all_in(lil_cub, params))
	{
		free_double_p(params);
		error_exit(E_REP, lil_cub);
	}
}

void read_map(t_cub *lil_cub, int fd)
{
	char	*tmp;
	char	*buffer;

	lil_cub->map = ft_strdup("");
	if (!lil_cub->map)
		error_exit(E_MALLOC, lil_cub);
	buffer = get_next_line(fd);
	if (!buffer)
		error_exit(E_EMPTY, lil_cub);
	while (buffer)
	{
		tmp = lil_cub->map;
		lil_cub->map = ft_strjoin(lil_cub->map, buffer);
		if (!lil_cub->map)
		{
			free(tmp);
			free(buffer);
			error_exit(E_MALLOC, lil_cub);
		}
		free(tmp);
		free(buffer);
		buffer = get_next_line(fd);
	}
}

void	parse_map(t_cub *lil_cub, char *arg)
{
	int fd;

	if (ft_strcmp(".cub", &arg[ft_strlen(arg) - 4]))
		error_exit(E_FORMAT, lil_cub);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		error_exit(E_OPEN, lil_cub);
	read_map(lil_cub, fd);
	close(fd);
	check_params(lil_cub);
	printf("%s\n", lil_cub->map); //quitarrr
	printf("NO - %p\nSO - %p\nEA - %p\nWE - %p\nC - %i\nF - %i\n", lil_cub->params->no, lil_cub->params->so, lil_cub->params->ea, lil_cub->params->we, lil_cub->params->c, lil_cub->params->f);
}
