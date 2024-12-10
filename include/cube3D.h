#ifndef CUBE3D_H
# define CUBE3D_H

#include <libft.h>
#include <MLX42.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_cub
{
	char *map;
}	t_cub;

//ERROR MSGS

#define E_ARGS "Error: Invalid number of args\n"
#define E_FORMAT "Error : Invalid map format\n"
#define E_MALLOC "Error"
#define E_OPEN "Error"
#define E_EMPTY "Error : Map is empty\n"

//INIT STRUCT

int	init_cube(t_cub *lil_cub);
int	parse_map(t_cub *lil_cub, char *arg);

//ERROR

int	error_exit(char *error, t_cub *cub);

#endif