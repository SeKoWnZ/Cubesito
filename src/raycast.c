#include <cube3D.h>

void	raycast(t_cub *cub, mlx_image_t *frame, int *i)
{
	double	ang;
	int		signx;
	int		signy;
	
	(void)frame;
	(void)i;
	ang = cub->player->pang;
	signx = 1;
	if (ang > rad_convertor(90) && ang < rad_convertor(270))
		signx = -1;
	signy = 1;
	if (ang > rad_convertor(180) && ang < rad_convertor(360))
		signy = -1;
	printf("SING X: %i\nSING Y: %i\n", signx, signy);
}
