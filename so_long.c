/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:34:12 by achivela          #+#    #+#             */
/*   Updated: 2024/08/30 13:34:14 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_arg(char *str)
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

void	verify(t_game *game)
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
		ft_error("\033[0;41mNão é possível inicializar o Window.");
	}
}

int	main(int argc, char const *argv[])
{
	int		fd;
	t_game	game;

	if (argc != 2 || !ft_check_arg((char *)argv[1]))
		ft_error("\033[0;41mVocê deve especificar o .ber");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("\033[0;41mNão é possível abrir o mapa.");
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_error("\033[0;41mNão é possível inicializar a biblioteca.");
	game.map = ft_get_map(fd);
	verify(&game);
	ft_render_map(game);
	mlx_hook(game.win, 17, 0, ft_close_win, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
