#ifndef CUBE3D_H
# define CUBE3D_H

#include <libft.h>
#include <MLX42.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>

#define y 0
#define x 1
#define W_WIDTH 800
#define W_HEIGHT 600
#define FOV 60

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

typedef struct s_player
{
	double		pox;
	double		poy;
	double		pang;
}	t_player;

typedef struct s_lil_ray
{
	double	cross[2];
	double	step[2];
	float	pix;
	double	dis;
	int		w_size;
	int		wface;
}	t_lil_ray;

typedef struct s_ray
{
	char **		map;
	double		pos[2];
	double		ang;
	double		ang_b;
	int			signx;
	int			signy;
	t_lil_ray	ray[2];
}	t_ray;

typedef struct s_cub
{
	mlx_t		*mlx;
	mlx_image_t *frame;
	char		*map;
	t_params	*params;
	t_player	*player;
}	t_cub;

//ERROR MSGS

#define E_ARGS "Error: Invalid number of args\n"
#define E_PARAM "Error: Invalid parameters\n"
#define E_MISS "Error: Missing parameters\n"
#define E_MAP "Error: The map parameters are incorrect\n"
#define E_FORMAT "Error: Invalid map format\n"
#define E_MALLOC "Error"
#define E_OPEN "Error"
#define E_EMPTY "Error: Map is empty\n"
#define E_REP "Error: Repeated parameters\n"
#define E_NLINE "Error: Empty line on map or space on param\n"
#define E_MLX "Error"

//INIT FUNCT

void	init_cube(t_cub *lil_cub);
void	init_player(t_cub *lil_cub);
void	parse_map(t_cub *lil_cub, char *arg);

//MLX THINGS

int		mlx_initialize(t_cub *cube);
void	mlx_run(t_cub *lil_cub);
void	cube_it(t_cub *cub);

//RAY THINGS

double	rad_convertor(double deg);
void	raycast(t_cub *cub, double ray_ang, int *i);
void	calculate_ray_x(t_ray *rey, t_params *param);
void	calculate_ray_y(t_ray *rey, t_params *param);
void	draw_ray(t_cub *cub, t_lil_ray *ray, int r, int i);

//PARSE

int		two_hi_n(char *map);
int		save_color(int *c, char *color);
int		check_n_save(t_cub *lil_cub, char **params, char **free_p);
int		valid_map(t_params *params, char **map);
int		square_map(t_params *params, char **map);

//KEYS

void	key_controls(void *param);

//ERROR

int		error_exit(char *error, t_cub *cub);
int		error_free(char *error, t_cub *lil_cub, char **free_p);

//FREE

void	free_double_p(char **p);

#endif