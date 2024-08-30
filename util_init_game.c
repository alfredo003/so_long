/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:11:52 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/05 09:11:55 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_attr(t_game *game)
{
	int	i;

	game->character.x = -1;
	game->character.y = -1;
	game->exit_place.x = -1;
	game->exit_place.y = -1;
	game->collectibles = NULL;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->height_map = i;
	i = 0;
	while (game->map[0][i] != '\0')
		i++;
	game->width_map = i;
}

void	ft_verify_load_img2(t_game *game)
{
	if (!game->empty_img)
	{
		ft_free_all(*game, 2);
		ft_error("The empty image was not loaded.");
	}
	if (!game->collectable_img)
	{
		ft_free_all(*game, 2);
		ft_error("The collectible image was not loaded.");
	}
	if (!game->exit_img)
	{
		ft_free_all(*game, 2);
		ft_error("The exit image was not loaded.");
	}
}

void	ft_verify_load_img1(t_game *game)
{
	if (!game->character_img)
	{
		ft_free_all(*game, 2);
		ft_error("The character image was not loaded.");
	}
	if (!game->obstacle_img)
	{
		ft_free_all(*game, 2);
		ft_error("The obstacle image was not loaded.");
	}
}

void	ft_init_imgs(t_game *game)
{
	int		w;
	int		h;
	void	*aux;

	aux = mlx_xpm_file_to_image(game->mlx, "./textures/P.xpm", &w, &h);
	game->character_img = aux;
	aux = mlx_xpm_file_to_image(game->mlx, "./textures/O.xpm", &w, &h);
	game->obstacle_img = aux;
	aux = mlx_xpm_file_to_image(game->mlx, "./textures/ETY.xpm", &w, &h);
	game->empty_img = aux;
	aux = mlx_xpm_file_to_image(game->mlx, "./textures/C.xpm", &w, &h);
	game->collectable_img = aux;
	aux = mlx_xpm_file_to_image(game->mlx, "./textures/E.xpm", &w, &h);
	game->exit_img = aux;
	ft_verify_load_img1(game);
	ft_verify_load_img2(game);
}

void	ft_init_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->character.x = j;
				game->character.y = i;
			}
			else if (game->map[i][j] == 'E')
			{
				game->exit_place.x = j;
				game->exit_place.y = i;
			}
			else if (game->map[i][j] == 'C')
				ft_store_collectable(i, j, game);
			j++;
		}
		i++;
	}
}
