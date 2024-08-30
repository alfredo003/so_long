/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_playing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:29:11 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/05 09:29:14 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_press2(int to_walk, unsigned long *walk, t_game game)
{
	if (to_walk == 1 || to_walk == 2)
	{
		(*walk)++;
		ft_print_walk(*walk);
		ft_render_map(game);
		if (to_walk == 2)
		{
			ft_free_all(game, 4);
			exit(0);
		}
	}
}

int	ft_key_press(int key, void *param)
{
	static unsigned long	walk = 0;
	t_game					*game;
	int						to_walk;

	to_walk = 0;
	game = (t_game *)param;
	if (key == 65307)
	{
		ft_free_all(*game, 4);
		exit(0);
	}
	else if (key == 97)
		to_walk = ft_key_down(game);
	else if (key == 100)
		to_walk = ft_key_right(game);
	else if (key == 119)
		to_walk = ft_key_top(game);
	else if (key == 115)
		to_walk = ft_key_left(game);
	ft_key_press2(to_walk, &walk, *game);
	return (0);
}

void	ft_render_map(t_game game)
{
	int		x;
	int		y;
	void	*tmp_i;

	y = 0;
	while (y < game.height_map)
	{
		x = 0;
		while (x < game.width_map)
		{
			if (game.map[y][x] == 'P')
				tmp_i = game.character_img;
			else if (game.map[y][x] == 'E')
				tmp_i = game.exit_img;
			else if (game.map[y][x] == 'C')
				tmp_i = game.collectable_img;
			else if (game.map[y][x] == '0')
				tmp_i = game.empty_img;
			else if (game.map[y][x] == '1')
				tmp_i = game.obstacle_img;
			mlx_put_image_to_window(game.mlx, game.win, tmp_i, x * PX, y * PX);
			x++;
		}
		y++;
	}
}
