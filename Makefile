# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 11:07:35 by acollon           #+#    #+#              #
#    Updated: 2025/07/18 12:49:38 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_BONUS	= so_long_bonus

SRC_DIR	= mandatory
SRC_DIR_BONUS = bonus
OBJ_DIR	= obj
OBJ_DIR_BONUS = obj_bonus
INC_DIR	= includes
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = mlx
MLX_FLAGS = -lXext -lX11 -lm

SRCS	= \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		$(SRC_DIR)/parsing/read_map.c \
		$(SRC_DIR)/parsing/error_handler.c \
		$(SRC_DIR)/parsing/parse_map.c \
		$(SRC_DIR)/parsing/validate_path.c \
		$(SRC_DIR)/display/render_map.c \
		$(SRC_DIR)/display/handle_input.c \

SRCS_BONUS	= \
		$(SRC_DIR_BONUS)/bonus/display_move.c \
		$(SRC_DIR_BONUS)/bonus/animation.c \
		$(SRC_DIR_BONUS)/bonus/enemy.c \
		$(SRC_DIR_BONUS)/bonus/enemy_list.c \
		$(SRC_DIR_BONUS)/bonus/enemy_dir.c \
		$(SRC_DIR_BONUS)/display/handle_input.c \
		$(SRC_DIR_BONUS)/display/render_map.c \
		$(SRC_DIR_BONUS)/parsing/error_handler.c \
		$(SRC_DIR_BONUS)/parsing/parse_map.c \
		$(SRC_DIR_BONUS)/parsing/read_map.c \
		$(SRC_DIR_BONUS)/parsing/validate_path.c 
			
# à compléter au fur et à mesure des tests

OBJS	= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBFT	= $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/ft_printf.a
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(FT_PRINTF) $(LIBFT) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
	
$(MLX):
	$(MAKE) -C $(MLX_DIR) all

bonus: $(NAME_BONUS)
	
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