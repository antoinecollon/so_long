# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 11:07:35 by acollon           #+#    #+#              #
#    Updated: 2025/05/14 15:14:38 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= includes
LIBFT_DIR = libft
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx_linux.a
MLX_FLAGS = -lXext -lX11 -lm
SRCS	= \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		parsing/read_map.c \
		parsing/error_handler.c \
		parsing/parse_map.c \
		parsing/validate_path.c \
			
# à compléter au fur et à mesure des tests

OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBFT	= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR) all
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re