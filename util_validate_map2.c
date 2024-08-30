/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_aux_validate_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:57:17 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 08:57:22 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_reverse_state2(t_game game)
{
	t_node_colectible	*aux;

	aux = game.collectibles;
	while (aux)
	{
		game.map[aux->collectible.y][aux->collectible.x] = 'C';
		aux = aux->next;
	}
}

void	ft_reverse_state(t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game.map[y] != NULL)
	{
		x = 0;
		while (game.map[y][x] != '\0')
		{
			if (game.map[y][x] == 'V')
				game.map[y][x] = '0';
			x++;
		}
		y++;
	}
	game.map[game.character.y][game.character.x] = 'P';
	ft_reverse_state2(game);
}

void	ft_have_path(char **m, t_position p, t_position c, int *achived)
{
	int			y;
	int			x;
	t_position	pos;

	ft_size_map(&x, &y, m);
	if (p.x == c.x && p.y == c.y)
		*achived = 1;
	else if (!((p.x >= 0 && p.x <= x) && (p.y >= 0 && p.y <= y)))
		return ;
	else if (m[p.y][p.x] != '1' && m[p.y][p.x] != 'E' && m[p.y][p.x] != 'V')
	{
		m[p.y][p.x] = 'V';
		pos = (t_position){p.x, p.y + 1};
		ft_have_path(m, pos, c, achived);
		pos = (t_position){p.x, p.y - 1};
		ft_have_path(m, pos, c, achived);
		pos = (t_position){p.x + 1, p.y};
		ft_have_path(m, pos, c, achived);
		pos = (t_position){p.x - 1, p.y};
		ft_have_path(m, pos, c, achived);
	}
}

void	ft_all_is_collectible(t_game game)
{
	int					achived;
	t_node_colectible	*aux;

	aux = game.collectibles;
	achived = 0;
	while (aux)
	{
		ft_have_path(game.map, game.character, aux->collectible, &achived);
		if (achived == 0)
		{
			ft_free_all(game, 3);
			ft_error("There is at least one unreachable collectible.");
		}
		achived = 0;
		ft_reverse_state(game);
		aux = aux->next;
	}
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
			ft_error("Invalid map - map have empty line.");
		}
		y++;
	}
}
