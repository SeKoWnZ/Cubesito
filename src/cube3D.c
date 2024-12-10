#include <cube3D.h>

int	main(int argc, char **argv)
{
	t_cub	lil_cub;

	if (argc == 2)
	{
		if (init_cube(&lil_cub))
			return(1);
		if (parse_map(&lil_cub, argv[1]))
			return(1);
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
