/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:36:24 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 10:36:29 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all2(t_game game, int coverage)
{
	if (coverage >= 0 && coverage <= 3)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}		
	if (coverage > 3)
	{
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}

void	ft_free_all(t_game game, int coverage)
{
	if (coverage > 0)
		ft_free_map(game.map);
	if (coverage > 1 && game.character_img)
		mlx_destroy_image(game.mlx, game.character_img);
	if (coverage > 1 && game.obstacle_img)
		mlx_destroy_image(game.mlx, game.obstacle_img);
	if (coverage > 1 && game.empty_img)
		mlx_destroy_image(game.mlx, game.empty_img);
	if (coverage > 1 && game.collectable_img)
		mlx_destroy_image(game.mlx, game.collectable_img);
	if (coverage > 1 && game.exit_img)
		mlx_destroy_image(game.mlx, game.exit_img);
	if (coverage > 2)
		ft_free_collectibles(game.collectibles);
	ft_free_all2(game, coverage);
}

void	ft_free_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->character_img);
	mlx_destroy_image(game->mlx, game->obstacle_img);
	mlx_destroy_image(game->mlx, game->empty_img);
	mlx_destroy_image(game->mlx, game->collectable_img);
	mlx_destroy_image(game->mlx, game->exit_img);
}

void	ft_free_collectibles(t_node_colectible *c)
{
	t_node_colectible	*aux;

	while (c)
	{
		aux = c->next;
		free(c);
		c = aux;
	}
}

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
}
