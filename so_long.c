/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:54:57 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/07/24 11:55:01 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4 || str[len - 1] != 'r')
		return (0);
	if (len < 4 || str[len - 2] != 'e')
		return (0);
	if (len < 4 || str[len - 3] != 'b')
		return (0);
	if (len < 4 || str[len - 4] != '.')
		return (0);
	return (1);
}

void	ft_prepare(t_game *game)
{
	int	cx;
	int	cy;

	ft_validate_map(*game);
	ft_init_attr(game);
	ft_init_imgs(game);
	ft_init_game(game);
	ft_all_is_collectible(*game);
	ft_exit_is_achived(*game);
	cy = game->height_map * PX;
	cx = game->width_map * PX;
	game->win = mlx_new_window(game->mlx, cx, cy, "so_long");
	if (!game->win)
	{
		ft_free_all(*game, 3);
		ft_error("Cannot initialize Window.");
	}
}

int	main(int argc, char const *argv[])
{
	int		fd;
	t_game	game;

	if (argc != 2 || !ft_is_ber((char *)argv[1]))
		ft_error("You should specify only the executable and the map .ber");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the map.");
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_error("Cannot initialize the library.");
	game.map = ft_get_map(fd);
	ft_prepare(&game);
	ft_render_map(game);
	mlx_hook(game.win, 17, 0, ft_close_win, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
