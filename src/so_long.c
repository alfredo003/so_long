/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:29:37 by achivela          #+#    #+#             */
/*   Updated: 2024/07/31 15:29:40 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int main(int argc,char **argv)
{
	t_game so_long;

	if(argc == 2)
	{
		so_long.map = read_map(argv[1]);
		if(map_checker(&so_long) && checker_file(argv[1]))
		{
			game_start(&so_long);
		}
		else
		{
			if (so_long.map)
				free_map(so_long.map);
			get_alert("\033[0;41mErro! Mapa Invalido !");
		}
		
	}
	else
		get_alert("\033[0;41mErro! Parametros Invalidos");
	return (0);
}

