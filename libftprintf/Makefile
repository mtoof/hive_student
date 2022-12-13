# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 08:54:34 by mtoof             #+#    #+#              #
#    Updated: 2022/12/12 08:55:01 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c \
		ft_convert.c
HEADER = ft_printf.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	
$(NAME):
	cc $(FLAGS) -c $(SRC) $(HEADER)
	ar rcs $(NAME) $(SRC:.c=.o)

clean:
	/bin/rm -f $(SRC:.c=.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all