/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_validate_map3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:27:52 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 12:27:59 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
