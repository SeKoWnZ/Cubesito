#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/MLX42.h"
#include "../include/libft.h"
#define WIDTH 512
#define HEIGHT 512

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

typedef struct s_data
{
	mlx_t *mlx;
	mlx_texture_t *texture[46];
	mlx_image_t* img[46];
}	t_data;

int32_t	main(void)
{
	t_data data;
		// Try to load the fill
	char	*s1 = ft_strdup("../textures/PNGS/0");
	char	*s11 = ft_strdup("../textures/PNGS/");
	char	*s3 = ft_strdup(".png");
	char	*s2;
	char	*s4;
	char	*s5;

	for (int i = 0; i < 46; i++)
	{
		s2 = ft_itoa(i + 1);
		if (i + 1 < 10)
			s4 = ft_strjoin(s1, s2);
		else
			s4 = ft_strjoin(s11, s2);
		s5 = ft_strjoin(s4, s3);
		data.texture[i] = mlx_load_png(s5);
		if (!data.texture[i])
			error();
		free(s2);
		free(s4);
		free(s5);
	}
	free(s1);
	free(s11);
	free(s3);

	// Start mlx
	data.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!data.mlx)
        error();

	// Convert texture to a displayable image
	for (int i = 0; i < 46; i++)
	{
		data.img[i] = mlx_texture_to_image(data.mlx, data.texture[i]);
		if (!data.img[i])
			error();
		if (mlx_image_to_window(data.mlx, data.img[i], 0, 0) < 0)
			error();
		if (i == 0)
			data.img[i]->enabled = true;
		else
			data.img[i]->enabled = false;
	}

	void	rotate(void *param)
	{
		static int frame_counter = 0;
		static int i;
		t_data *game = (t_data *)param;

		if (++frame_counter >= 10) {
			frame_counter = 0;
			game->img[i % 46]->enabled = false;
			i++;
			game->img[i % 46]->enabled = true;
		}
	}

	mlx_loop_hook(data.mlx, &rotate, &data);

	mlx_loop(data.mlx);

	for (int i = 0; i < 46; i ++){
		mlx_delete_image(data.mlx, data.img[i]);
	}
	for (int i = 0; i < 46; i ++){
		mlx_delete_texture(data.texture[i]);
	}
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}