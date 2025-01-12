# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 18:26:02 by phuocngu          #+#    #+#              #
#    Updated: 2025/01/12 17:58:20 by phuocngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/mandatory
BONUS_DIR = ./src/bonus

UTILS_DIR = ./utils

SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/initial_setup.c \
	$(SRC_DIR)/child_process.c \
	$(SRC_DIR)/execute.c \
	$(SRC_DIR)/utils.c \
	$(UTILS_DIR)/ft_perror.c \
	$(UTILS_DIR)/path_utils.c \

BONUS_FILES = \
	$(BONUS_DIR)/main_bonus.c \
	$(BONUS_DIR)/initial_setup_bonus.c \
	$(BONUS_DIR)/child_process_bonus.c \
	$(SRC_DIR)/execute.c \
	$(SRC_DIR)/utils.c \
	$(UTILS_DIR)/ft_perror.c \
	$(UTILS_DIR)/path_utils.c \

OBJS = $(SRC_FILES:.c=.o)

NAME = pipex

LIBFT_DIR = lib/libft
LIBFT_NAME = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH)

bonus: $(LIBFT_DIR) $(BONUS_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_FILES) $(LIBFT_PATH)
	touch bonus

$(LIBFT_PATH):
	make -C $(LIBFT_DIR)

clean:
	rm bonus
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
