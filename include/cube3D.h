#ifndef CUBE3D_H
# define CUBE3D_H

#include <libft.h>
#include <MLX42.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_cub
{
	char		*map;
	t_params	*params;
}	t_cub;

typedef struct s_params
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	int				c;
	int				f;
	char	**map;
}	t_params;

//ERROR MSGS

#define E_ARGS "Error: Invalid number of args\n"
#define E_FORMAT "Error: Invalid map format\n"
#define E_MALLOC "Error"
#define E_OPEN "Error"
#define E_EMPTY "Error: Map is empty\n"
#define E_REP "Error: Repeated parameters\n"

//INIT STRUCT

void	init_cube(t_cub *lil_cub);
void	parse_map(t_cub *lil_cub, char *arg);

//ERROR

int		error_exit(char *error, t_cub *cub);

//FREE

void	free_double_p(char **p);

#endif