/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:45:47 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/07/25 09:45:52 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 36
# define PX 48

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct positions{
	int	x;
	int	y;
}	t_position;

typedef struct list{
	t_position	collectible;
	struct list	*next;
}	t_node_colectible;

typedef struct game_s{
	int					width_map;
	int					height_map;
	char				**map;
	void				*mlx;
	void				*win;
	void				*character_img;
	void				*obstacle_img;
	void				*empty_img;
	void				*collectable_img;
	void				*exit_img;
	t_position			character;
	t_position			exit_place;
	t_node_colectible	*collectibles;
}	t_game;

int		ft_strlen(char *s);
int		ft_key_top(t_game *g);
int		ft_key_down(t_game *g);
int		ft_key_left(t_game *g);
int		ft_key_right(t_game *g);
int		ft_close_win(void *param);
int		ft_key_press(int key, void *param);
int		ft_qtd_character(char **map, char c);
char	*ft_putin_line(char *line, char c);
char	**ft_putin_map(char **map, char *line);
char	*ft_get_next_line(int fd, int *new_line_end);
char	**ft_get_map(int fd);
void	ft_error(char *s);
void	ft_prepare(t_game *game);
void	ft_exit_is_achived(t_game game);
void	ft_store_collectable(int y, int x, t_game *game);
void	ft_init_attr(t_game *game);
void	ft_init_game(t_game *game);
void	ft_init_imgs(t_game *game);
void	ft_render_map(t_game game);
void	ft_free_imgs(t_game *game);
void	ft_size_map(int *width, int *height, char **map);
void	ft_surrounded_wall(t_game game);
void	ft_mandatories_characters(t_game game);
void	ft_no_empty_line(t_game game);
void	ft_rectangular_map(t_game game);
void	ft_qtd_mandatories_characters(t_game game);
void	ft_validate_map(t_game game);
void	ft_get_pos(int *x, int *y, char **map, char c);
void	ft_all_is_collectible(t_game game);
void	ft_have_path(char **m, t_position p, t_position c, int *achived);
void	ft_reverse_state(t_game game);
void	ft_reverse_state2(t_game game);
void	ft_print_walk(unsigned long nb);
void	ft_free_map(char **map);
void	ft_free_collectibles(t_node_colectible *c);
void	ft_free_all(t_game game, int coverage);
void	ft_putin_line1(char **new_, char c);
void	ft_putin_map1(char ***new_, char *line);
void	ft_putin_map2(char ***new_, char *line, char **m, int i);
void	ft_rm_collectable(t_node_colectible **collectibles, int y, int x);
#endif
