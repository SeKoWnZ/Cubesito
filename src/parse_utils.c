#include <cube3D.h>

int	two_hi_n(char *map)
{
	int	i;
	int in_map;

	i = -1;
	in_map = 0;
	while (map[++i])
	{
		if (map[i] == '\n' && (map[i + 1] == ' ' || map[i + 1] == '0' || map[i + 1] == '1'))
			in_map = 1;
		if (in_map == 1 && map[i] == '\n' && (map[i + 1] == '\n'))
			return(1);
	}
	return(0);
}
