/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:01:23 by sarajime          #+#    #+#             */
/*   Updated: 2025/02/11 20:01:27 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	main(int argc, char **argv)
{
	t_cub	lil_cub;

	if (argc == 2)
	{
		init_cube(&lil_cub);
		parse_map(&lil_cub, argv[1]);
		mlx_run(&lil_cub);
		free_nano(NULL, &lil_cub);
	}
	else
	{
		ft_printf(E_ARGS);
		return(1);
	}
	return(0);
}
