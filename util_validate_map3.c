/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_validate_map3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:01:42 by achivela          #+#    #+#             */
/*   Updated: 2024/08/30 16:01:47 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_size_map(int *width, int *height, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
		y++;
	while (map[0][x] != '\0')
		x++;
	*width = x - 1;
	*height = y - 1;
}

void	ft_print_walk(unsigned long nb)
{
	char	c;

	if (nb == 0)
	{
		write (1, "\n", 1);
		return ;
	}
	ft_print_walk(nb / 10);
	c = (nb % 10) + '0';
	write (1, &c, 1);
}

void	ft_no_empty_line(t_game game)
{
	int	x;
	int	y;

	y = 0;
	while (game.map[y] != NULL)
	{
		x = ft_strlen(game.map[y]);
		if (x == 0)
		{
			ft_free_all(game, 1);
			ft_error("\033[0;41mMapa inválido - o mapa possui uma linha vazia.");
		}
		y++;
	}
}

void	ft_exit_is_achived(t_game game)
{
	int	achived;

	achived = 0;
	ft_have_path(game.map, game.character, game.exit_place, &achived);
	if (!achived)
	{
		ft_free_all(game, 3);
		ft_error("The game exit is not achievable.");
	}
	ft_reverse_state(game);
}

int	ft_qtd_character(char **map, char c)
{
	int	qtd;
	int	x;
	int	y;

	qtd = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
				qtd++;
			x++;
		}
		y++;
	}
	return (qtd);
}
