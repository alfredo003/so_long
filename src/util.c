/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:48:10 by achivela          #+#    #+#             */
/*   Updated: 2024/08/02 13:48:13 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(char *path)
{
    int fd;
    char *line;
    char *holder_map;
    char *holder;
    char **map;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    holder_map = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        holder = holder_map;
        holder_map = ft_strjoin(holder, line);
        free(line);
        free(holder);
    }
    map = ft_split(holder_map, '\n');
    free(holder_map);
    close(fd);
    return (map);
}

static int checker_file(char *argv)
{
	int i;
	
	if(!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

void get_alert(char *str)
{
	while(*str)
	{
		write(1,str,1);
		str++;
	}
	write(1,"\n",1);
	exit(1);
}
