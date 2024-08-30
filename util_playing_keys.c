/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_playing_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:37:50 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 08:37:58 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_top(t_game *g)
{
	if (g->map[g->character.y - 1][g->character.x] == '0')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y - 1][g->character.x] = 'P';
		g->character.y = g->character.y - 1;
	}
	else if (g->map[g->character.y - 1][g->character.x] == 'C')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y - 1][g->character.x] = 'P';
		g->character.y = g->character.y - 1;
		ft_rm_collectable(&g->collectibles, g->character.y, g->character.x);
	}
	else if (g->map[g->character.y - 1][g->character.x] == 'E')
	{
		if (g->collectibles == NULL)
			return (2);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	ft_key_down(t_game *g)
{
	if (g->map[g->character.y + 1][g->character.x] == '0')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y + 1][g->character.x] = 'P';
		g->character.y = g->character.y + 1;
	}
	else if (g->map[g->character.y + 1][g->character.x] == 'C')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y + 1][g->character.x] = 'P';
		g->character.y = g->character.y + 1;
		ft_rm_collectable(&g->collectibles, g->character.y, g->character.x);
	}
	else if (g->map[g->character.y + 1][g->character.x] == 'E')
	{
		if (g->collectibles == NULL)
			return (2);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	ft_key_left(t_game *g)
{
	if (g->map[g->character.y][g->character.x - 1] == '0')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y][g->character.x - 1] = 'P';
		g->character.x = g->character.x - 1;
	}
	else if (g->map[g->character.y][g->character.x - 1] == 'C')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y][g->character.x - 1] = 'P';
		g->character.x = g->character.x - 1;
		ft_rm_collectable(&g->collectibles, g->character.y, g->character.x);
	}
	else if (g->map[g->character.y][g->character.x - 1] == 'E')
	{
		if (g->collectibles == NULL)
			return (2);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	ft_key_right(t_game *g)
{
	if (g->map[g->character.y][g->character.x + 1] == '0')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y][g->character.x + 1] = 'P';
		g->character.x = g->character.x + 1;
	}
	else if (g->map[g->character.y][g->character.x + 1] == 'C')
	{
		g->map[g->character.y][g->character.x] = '0';
		g->map[g->character.y][g->character.x + 1] = 'P';
		g->character.x = g->character.x + 1;
		ft_rm_collectable(&g->collectibles, g->character.y, g->character.x);
	}
	else if (g->map[g->character.y][g->character.x + 1] == 'E')
	{
		if (g->collectibles == NULL)
			return (2);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}
