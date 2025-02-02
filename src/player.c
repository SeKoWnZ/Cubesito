#include <cube3D.h>

double	rad_convertor(double deg)
{
	return (deg * (M_PI / 180));
}

void	init_player(t_cub *lil_cub)
{
	int i;
	int	j;

	j = -1;
	while (lil_cub->params->map[++j])
	{
		i = -1;
		while (lil_cub->params->map[j][++i])
		{
			if (ft_strchr("NEWS", lil_cub->params->map[j][i]))
			{
				lil_cub->player->pox = i + 0.5;
				lil_cub->player->poy = j + 0.5;
			}
			if (lil_cub->params->map[j][i] == 'S')
				lil_cub->player->pang = rad_convertor(90);
			if (lil_cub->params->map[j][i] == 'N')
				lil_cub->player->pang = rad_convertor(270);
			if (lil_cub->params->map[j][i] == 'E')
				lil_cub->player->pang = rad_convertor(0);
			if (lil_cub->params->map[j][i] == 'W')
				lil_cub->player->pang = rad_convertor(180);
		}
	}
}
