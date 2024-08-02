#include "so_long.h"

static int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int map_checker(t_game *game)
{
	if(is_retangular(game->map))
		return (1);
	return (0);
}
