/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:02:40 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:35 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	move_player(t_cub *cub, double mov_x, double mov_y)
{
	cub->player->pox += mov_x / 50.0;
	if (cub->params->map[(int)(cub->player->poy - 0.1)]
		[(int)(cub->player->pox - 0.1)] == '1'
		|| cub->params->map[(int)(cub->player->poy + 0.1)]
		[(int)(cub->player->pox + 0.1)] == '1'
		|| cub->params->map[(int)(cub->player->poy + 0.1)]
		[(int)(cub->player->pox - 0.1)] == '1'
		|| cub->params->map[(int)(cub->player->poy - 0.1)]
		[(int)(cub->player->pox + 0.1)] == '1')
		cub->player->pox -= mov_x / 50.0;
	cub->player->poy += mov_y / 50.0;
	if (cub->params->map[(int)(cub->player->poy - 0.1)]
		[(int)(cub->player->pox - 0.1)] == '1'
		|| cub->params->map[(int)(cub->player->poy + 0.1)]
		[(int)(cub->player->pox + 0.1)] == '1'
		|| cub->params->map[(int)(cub->player->poy + 0.1)]
		[(int)(cub->player->pox - 0.1)] == '1'
		|| cub->params->map[(int)(cub->player->poy - 0.1)]
		[(int)(cub->player->pox + 0.1)] == '1')
		cub->player->poy -= mov_y / 50.0;
}

void	mouse_controls(t_cub *cub)
{
	static int	equis;
	static int	ye;

	mlx_get_mouse_pos(cub->mlx, &equis, &ye);
	cub->player->pang += rad_convertor((equis - W_WIDTH / 2) / 50.0);
	mlx_set_mouse_pos(cub->mlx, W_WIDTH / 2, W_HEIGHT / 2);
}

void	key_controls(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		move_player(cub, cos(cub->player->pang), -sin(cub->player->pang));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		move_player(cub, -cos(cub->player->pang), sin(cub->player->pang));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		move_player(cub, -cos(cub->player->pang + M_PI / 2),
			sin(cub->player->pang + M_PI / 2));
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		move_player(cub, cos(cub->player->pang + M_PI / 2),
			-sin(cub->player->pang + M_PI / 2));
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
	mouse_controls(cub);
}

void	gameloop(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	key_controls(cub);
	cube_it(cub);
	rotate(cub);
}
