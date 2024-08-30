/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:41:47 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 10:41:51 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_free_all(*game, 4);
	exit(0);
}

void	ft_error(char *s)
{
	int	i;

	i = 0;
	write (2, "Error\n", 6);
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}
