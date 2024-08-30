/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_validate_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:44:39 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/09 10:44:41 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_surrounded_wall(t_game game)
{
	int	i;
	int	width_map;
	int	height_map;

	i = 0;
	ft_size_map(&width_map, &height_map, game.map);
	while (i <= width_map)
	{
		if (game.map[0][i] != '1' || game.map[height_map][i] != '1')
		{
			ft_free_all(game, 1);
			ft_error("Invalid map - not surrounded by 1");
		}
		i++;
	}
	i = 0;
	while (i <= height_map)
	{
		if (game.map[i][0] != '1' || game.map[i][width_map] != '1')
		{
			ft_free_all(game, 1);
			ft_error("Invalid map - not surrounded by 1");
		}
		i++;
	}
}

void	ft_mandatories_characters(t_game game)
{
	int	x;
	int	y;
	int	deny_char;

	y = 0;
	deny_char = 0;
	while (game.map[y] != NULL)
	{
		x = 0;
		while (game.map[y][x] != '\0')
		{
			if (game.map[y][x] != '0' && game.map[y][x] != '1')
				deny_char++;
			if (game.map[y][x] != 'C' && game.map[y][x] != 'E')
				deny_char++;
			if (game.map[y][x] != 'P' && deny_char == 2)
			{
				ft_free_all(game, 1);
				ft_error("Invalid map - invalid character.");
			}
			deny_char = 0;
			x++;
		}
		y++;
	}
}

void	ft_rectangular_map(t_game game)
{
	int	first_line;
	int	width;
	int	height;

	first_line = 0;
	height = 1;
	while (game.map[0][first_line] != '\0')
		first_line++;
	while (game.map[height] != NULL)
	{
		width = 0;
		while (game.map[height][width] != '\0')
			width++;
		if (width != first_line)
		{
			ft_free_all(game, 1);
			ft_error("Invalid map - map isnt rectangular.");
		}
		height++;
	}
}

void	ft_qtd_mandatories_characters( t_game game)
{
	if (ft_qtd_character(game.map, 'E') != 1)
	{
		ft_free_all(game, 1);
		ft_error("Invalid map - must contain 1 exit.");
	}
	if (ft_qtd_character(game.map, 'C') < 1)
	{
		ft_free_all(game, 1);
		ft_error("Invalid map - at least 1 collectible");
	}
	if (ft_qtd_character(game.map, 'P') != 1)
	{
		ft_free_all(game, 1);
		ft_error("Invalid map - must contain 1 starting position.");
	}
}

void	ft_validate_map(t_game game)
{
	ft_no_empty_line(game);
	ft_rectangular_map(game);
	ft_surrounded_wall(game);
	ft_mandatories_characters(game);
	ft_qtd_mandatories_characters(game);
}
