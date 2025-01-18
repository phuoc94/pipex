# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:52:44 by phuocngu          #+#    #+#              #
#    Updated: 2025/01/18 12:57:14 by phuocngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = \
	validation/ft_isint.c \
	validation/ft_isnumber.c \
	character/ft_isalpha.c \
	character/ft_isdigit.c \
	character/ft_isalnum.c \
	character/ft_isascii.c \
	character/ft_isprint.c \
	character/ft_toupper.c \
	character/ft_tolower.c \
	character/ft_isspace.c \
	string/ft_strlen.c \
	string/ft_strchr.c \
	string/ft_strrchr.c \
	string/ft_strncmp.c \
	string/ft_strcmp.c \
	string/ft_strlcpy.c \
	string/ft_strlcat.c \
	string/ft_strdup.c \
	string/ft_strclen.c \
	string/ft_substr.c \
	string/ft_strjoin.c \
	string/ft_strtrim.c \
	string/ft_split.c \
	string/ft_strmapi.c \
	string/ft_striteri.c \
	string/ft_strnstr.c \
	memory/ft_memset.c \
	memory/ft_bzero.c \
	memory/ft_memcpy.c \
	memory/ft_memmove.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_calloc.c \
	conversion/ft_atoi.c \
	conversion/ft_itoa.c \
	conversion/ft_atof.c \
	conversion/ft_strtol.c \
	output/ft_putchar_fd.c \
	output/ft_putendl_fd.c \
	output/ft_putstr_fd.c \
	output/ft_putnbr_fd.c

GNL_DIR = get_next_line
GNL_SRC_FILES = \
	get_next_line.c \

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRC_FILES = \
	ft_printf.c \
	ft_print_ptr.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_nbr.c

SRC_FILES += \
	$(addprefix $(GNL_DIR)/, $(GNL_SRC_FILES)) \
	$(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC_FILES))

OBJS = $(SRC_FILES:.c=.o)

NAME = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
