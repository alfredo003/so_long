# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achivela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:06:23 by achivela          #+#    #+#              #
#    Updated: 2024/07/31 15:06:26 by achivela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L. -lXext -L. -lX11

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./libs/minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRC_FILES = so_long.c \
		util.c \
		game_start.c \
		map_verify.c

SRC_DIR = src

HEADER = $(SRC_DIR)/so_long.h

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS = $(SRCS:.c=.o)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)
$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx

