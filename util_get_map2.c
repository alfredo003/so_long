/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_get_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:05:56 by achivela          #+#    #+#             */
/*   Updated: 2024/08/30 16:05:58 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_putin_line1(char **new_, char c)
{
	*new_ = (char *)malloc(sizeof(char) * 2);
	if (!(*new_))
		ft_error("Cannot read map.");
	(*new_)[0] = c;
	(*new_)[1] = '\0';
}

char	*ft_putin_line(char *line, char c)
{
	int		i;
	char	*new;

	new = NULL;
	if (line == NULL)
		ft_putin_line1(&new, c);
	else
	{
		i = 0;
		new = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2));
		if (!new)
			ft_error("Cannot read map.");
		while (line[i] != '\0')
		{
			new[i] = line[i];
			i++;
		}
		new[i] = c;
		new[i + 1] = '\0';
	}
	free(line);
	return (new);
}

void	ft_putin_map1(char ***new_, char *line)
{
	*new_ = (char **)malloc(sizeof(char *) * 2);
	if (!(*new_))
		ft_error("Cannot read map.");
	(*new_)[0] = line;
	(*new_)[1] = NULL;
}

void	ft_putin_map2(char ***new_, char *line, char **m, int i)
{
	int	j;

	j = 0;
	*new_ = (char **)malloc(sizeof(char *) * (i + 1));
	if (!(*new_))
		ft_error("Cannot read map.");
	while (j < i - 1)
	{
		(*new_)[j] = m[j];
		j++;
	}
	(*new_)[j] = line;
	(*new_)[j + 1] = NULL;
}

char	**ft_putin_map(char **map, char *line)
{
	char			**novo;
	static int		i = 0;

	novo = NULL;
	if (map == NULL)
	{
		ft_putin_map1(&novo, line);
		i = 2;
	}
	else
	{
		ft_putin_map2(&novo, line, map, (int)i);
		i++;
	}
	free(map);
	return (novo);
}
