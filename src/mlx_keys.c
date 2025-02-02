#include <cube3D.h>

void move_player(t_cub *cub, double mov_x, double mov_y)
{
	printf("ANG = %f\nMOVX = %f\nMOVY = %f\n", cub->player->pang, mov_x, mov_y);
	cub->player->pox += mov_x / 50.0;
	cub->player->poy += mov_y / 50.0;
}

void	key_controls(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		move_player(cub, cos(cub->player->pang), -sin(cub->player->pang));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		move_player(cub, -cos(cub->player->pang), sin(cub->player->pang));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		move_player(cub, -cos(cub->player->pang + M_PI / 2), sin(cub->player->pang + M_PI / 2));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		move_player(cub, cos(cub->player->pang + M_PI / 2), -sin(cub->player->pang + M_PI / 2));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window((mlx_t *)cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->player->pang -= rad_convertor(1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->player->pang += rad_convertor(1);
	if (cub->player->pang < rad_convertor(0))
		cub->player->pang += rad_convertor(360);
	if (cub->player->pang > rad_convertor(360))
		cub->player->pang -= rad_convertor(360);
}

void	gameloop(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	key_controls(cub);
	cube_it(cub);
	rotate(cub);
}
