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

static int	is_wall(char **map)
{
	int i;
	int j;
	int len;
	
	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0])
}

int map_checker(t_game *game)
{
	if(is_retangular(game->map) && is_wall(game->map))
		return (1);
	return (0);
}
