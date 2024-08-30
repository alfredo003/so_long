# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 13:07:55 by gudos-sa          #+#    #+#              #
#    Updated: 2024/07/23 13:42:13 by gudos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	so_long.c \
	utils.c \
	util_init_game.c \
	util_get_map.c \
	util_get_map2.c \
	util_playing.c \
	util_playing_keys.c \
	util_validate_map.c \
	util_validate_map2.c \
	util_validate_map3.c \
	utils_free.c \
	utils_finish.c
	
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
