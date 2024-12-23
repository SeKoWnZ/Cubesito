#include <cube3D.h>

void	check_params(t_cub *lil_cub)
{
	char **params;

	if (two_hi_n(lil_cub->map))
		error_exit(E_NLINE, lil_cub);
	params = ft_split(lil_cub->map, '\n');
	if (check_n_save(lil_cub, params))
	{
		free_double_p(params);
		error_exit(E_REP, lil_cub);
	}
	free_double_p(params);
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
	printf("NO - %p\nSO - %p\nEA - %p\nWE - %p\nC - %i\nF - %i\nMAXy: %i\nMAXx: %i\n", lil_cub->params->no, lil_cub->params->so, lil_cub->params->ea, lil_cub->params->we, lil_cub->params->c, lil_cub->params->f, lil_cub->params->max[x], lil_cub->params->max[y]);
	while (*lil_cub->params->map)
	{
		printf("%s|\n", *lil_cub->params->map);
		lil_cub->params->map++;
	}
}
