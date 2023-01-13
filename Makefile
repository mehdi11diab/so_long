# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ediab <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 20:11:11 by ediab             #+#    #+#              #
#    Updated: 2022/12/19 20:11:15 by ediab            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Wall -Wextra -Werror
MFLAG = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRC = src/main.c src/so_long.c src/map_calc.c src/extra_flood.c src/get_next_line_utils.c src/get_next_line.c src/ft_split.c src/validmap.c src/image.c src/mouves.c src/ft_printf.c src/flood.c src/ft_putchar.c src/ft_putnbr.c src/ft_putstr.c src/ft_itoa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) $(MFLAG) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
