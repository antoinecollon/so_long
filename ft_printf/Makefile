# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 14:39:44 by acollon           #+#    #+#              #
#    Updated: 2025/05/24 14:20:15 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC_DIR = src
SRC		=	$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_putchar.c \
			$(SRC_DIR)/ft_putstr.c \
			$(SRC_DIR)/ft_putnbr.c \
			$(SRC_DIR)/ft_putnbr_unsigned.c \
			$(SRC_DIR)/ft_puthex.c \
			$(SRC_DIR)/ft_putptr.c \
			$(SRC_DIR)/ft_dispatch.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# TEST_SRC = test/main.c
# TEST_EXE = test_printf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
#	$(RM) $(TEST_EXE)

re: fclean all

# test: $(NAME)
#	cd $(LIBFT_DIR) && $(MAKE)
#	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -L$(LIBFT_DIR) -lft -o $(TEST_EXE)

.PHONY: clean re fclean all test
