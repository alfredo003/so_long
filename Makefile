# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achivela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 13:23:54 by achivela          #+#    #+#              #
#    Updated: 2024/08/30 13:23:59 by achivela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	so_long.c \
	utils.c \
	init_game.c \
	get_map.c \
	util_get_map2.c \
	playing.c \
	playing_keys.c \
	validate_map.c \
	aux_validate_map.c \
	util_validate_map3.c \
	free_map.c
	
OBJ = $(SRC:.c=.o)
INCLUDES =  -I ./minilibx-linux
LIBRARIES = -L ./minilibx-linux -lmlx -lm -lX11 -lXext

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./minilibx-linux
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBRARIES) -o $(NAME)

clean: 
	make clean -C ./minilibx-linux
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
