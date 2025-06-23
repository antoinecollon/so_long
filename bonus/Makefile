# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 11:07:35 by acollon           #+#    #+#              #
#    Updated: 2025/06/19 18:41:17 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= includes
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm
SRCS	= \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		parsing/read_map.c \
		parsing/error_handler.c \
		parsing/parse_map.c \
		parsing/validate_path.c \
		display/render_map.c \
		display/handle_input.c \
		bonus/display_move.c \
		animation/animation.c \
		display/enemy.c
			
# à compléter au fur et à mesure des tests

OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBFT	= $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/ft_printf.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
	
$(MLX):
	$(MAKE) -C $(MLX_DIR) all
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re