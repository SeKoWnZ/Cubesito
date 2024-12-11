#include <cube3D.h>

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
	printf("%s\n", lil_cub->map); //quitarrr
}
