/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:39:24 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/07/26 15:37:16 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_size_map(int *width, int *height, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
		y++;
	while (map[0][x] != '\0')
		x++;
	*width = x - 1;
	*height = y - 1;
}

void	ft_print_walk(unsigned long nb)
{
	char	c;

	if (nb == 0)
	{
		write (1, "\n", 1);
		return ;
	}
	ft_print_walk(nb / 10);
	c = (nb % 10) + '0';
	write (1, &c, 1);
}

void	ft_store_collectable(int y, int x, t_game *game)
{
	t_node_colectible	*new;
	t_node_colectible	*aux;

	new = (t_node_colectible *)malloc(sizeof(t_node_colectible));
	if (!new)
	{
		ft_free_all(*game, 3);
		ft_error("Cannot read map.");
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
