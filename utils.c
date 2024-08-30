/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:21:02 by achivela          #+#    #+#             */
/*   Updated: 2024/08/30 16:05:21 by achivela         ###   ########.fr       */
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_store_collectable(int y, int x, t_game *game)
{
	t_node_colectible	*new;
	t_node_colectible	*aux;

	new = (t_node_colectible *)malloc(sizeof(t_node_colectible));
	if (!new)
	{
		ft_free_all(*game, 3);
		ft_error("\033[0;41mNão é possível ler o mapa.");
	}
	new->collectible.x = x;
	new->collectible.y = y;
	new->next = NULL;
	if (game->collectibles == NULL)
		game->collectibles = new;
	else
	{
		aux = game->collectibles;
		while (aux && aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

void	ft_rm_collectable(t_node_colectible **collectibles, int y, int x)
{
	t_node_colectible	*aux;
	t_node_colectible	*prev;

	aux = *collectibles;
	prev = NULL;
	while (aux)
	{
		if (aux->collectible.y == y && aux->collectible.x == x)
			break ;
		prev = aux;
		aux = aux->next;
	}
	if (aux)
	{
		if (prev)
			prev->next = aux->next;
		else if (aux->next)
			*collectibles = aux->next;
		else
			*collectibles = NULL;
		free(aux);
	}
}
