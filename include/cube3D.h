#ifndef CUBE3D_H
# define CUBE3D_H

#include <libft.h>
#include <MLX42.h>
#include <errno.h>
#include <fcntl.h>

#define y 0
#define x 1
#define W_WIDTH 800
#define W_HEIGHT 600

typedef struct s_params
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	int				c;
	int				f;
	int				max[2];
	char			**map;
}	t_params;

typedef struct s_cub
{
	char		*map;
	t_params	*params;
	mlx_t		*mlx;
}	t_cub;

//ERROR MSGS

#define E_ARGS "Error: Invalid number of args\n"
#define E_FORMAT "Error: Invalid map format\n"
#define E_MALLOC "Error"
#define E_OPEN "Error"
#define E_EMPTY "Error: Map is empty\n"
#define E_REP "Error: Repeated parameters\n"
#define E_NLINE "Error: Empty line on map\n"
#define E_MLX "Error"

//INIT STRUCT

void	init_cube(t_cub *lil_cub);
void	parse_map(t_cub *lil_cub, char *arg);

//PARSE

int	two_hi_n(char *map);
int	save_color(int *c, char *color);
int	check_n_save(t_cub *lil_cub, char **params);
int	valid_map(t_params *params, char **map);
int	square_map(t_params *params, char **map);

//ERROR

int		error_exit(char *error, t_cub *cub);

//FREE

void	free_double_p(char **p);

#endif