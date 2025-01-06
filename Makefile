# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 18:26:02 by phuocngu          #+#    #+#              #
#    Updated: 2025/01/06 15:30:00 by phuocngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src

SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/initial_setup.c \

OBJS = $(SRC_FILES:.c=.o)

NAME = pipex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT_DIR = lib/libft
LIBFT_NAME = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT_NAME)

$(LIBFT_PATH):
	make -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
