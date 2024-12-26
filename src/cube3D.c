#include <cube3D.h>

int	main(int argc, char **argv)
{
	t_cub	lil_cub;

	if (argc == 2)
	{
		init_cube(&lil_cub);
		parse_map(&lil_cub, argv[1]);
		mlx_run(&lil_cub);
	}
	else
	{
		ft_printf(E_ARGS);
		return(1);
	}
	return(0);
	//PARSEITO DEL MAPA;
	//INICIO DE MLX Y RELLENARLA;
	//LIMPIEZA DE TODO;
}
