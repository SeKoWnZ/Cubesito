#include <cube3D.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	color_allnums_ok(char *color)
{
	int	i;
	int	n_comma;

	i = 0;
	n_comma = 0;
	while (color[i])
	{
		if (!ft_strchr(",1234567890", color[i]))
			return(1);
		else if (color[i] == ',')
			n_comma++;
		i++;
	}
	if (n_comma != 2)
		return(1);
	return(0);
}

int color_set(char **nums, int rgb[3])
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	if (i != 3)
		return (1);
	while (--i >= 0)
	{
		if (!ft_atoitoa_cmp(nums[i]))
		{
			rgb[i] = ft_atoi(nums[i]);
			if (rgb[i] < 0 || rgb[i] > 255)
				return(1);
		}
		else
			return(1);
	}
	return(0);
}

int	save_color(int *c, char *color)
{
	char	**nums;
	int		rgb[3];
	
	if (*c != -1)
		return (1);
	while (*color && *color == ' ')
		color++;
	if (color_allnums_ok(color))
		return(1);
	nums = ft_split(color, ',');
	if (!nums)
		return(1);
	if (color_set(nums, rgb))
	{
		free_double_p(nums);
		return(1);
	}
	free_double_p(nums);
	*c = get_rgba(rgb[0], rgb[1], rgb[2], 255);
	return(0);
}
