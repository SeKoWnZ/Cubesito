#include <cube3D.h>

double	*first_x(float *r_pos, double ang, int signx)
{
	float	r_step[2];

	if (signx == 1)
		r_step[x] = ((int)r_pos[x] + 1) - r_pos[x];
	else
		r_step[x] = (int)r_pos[x] - r_pos[x];
	r_step[y] = r_step[x] / tan(ang);
	r_step[y] = r_step[y] + r_pos[y];
	return (r_step);
}

double	*first_y(float *r_pos, double ang, int signy)
{
	float	r_step[2];

	if (signy == 1)
		r_step[y] = ((int)r_pos[y] + 1) - r_pos[y];
	else
		r_step[y] = (int)r_pos[y] - r_pos[y];
	r_step[x] = r_step[y] * tan(ang);
	r_step[x] = r_step[x] + r_pos[x];
	return (r_step);
}
void	raycast(t_cub *cub, mlx_image_t *frame, int *i)
{
	double	ang;
	int		signx;
	int		signy;
	float	ray_pos[2];
	
	(void)frame;
	(void)i;
	ang = cub->player->pang;
	ray_pos[x] = cub->player->pox;
	ray_pos[y] = cub->player->poy;
	signx = 1;
	if (ang > rad_convertor(90) && ang < rad_convertor(270))
		signx = -1;
	signy = 1;
	if (ang > rad_convertor(180) && ang < rad_convertor(360))
		signy = -1;
	printf("SING X: %i\nSING Y: %i\n", signx, signy);
	first_x(ray_pos, ang, signx);
	first_y(ray_pos, ang, signy);
}
