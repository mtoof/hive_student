# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:50:23 by mtoof             #+#    #+#              #
#    Updated: 2022/10/27 17:12:35 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c
SRC += ft_isprint.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlen.c ft_tolower.c
SRC += ft_toupper.c
OBJ = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o 
OBJ += ft_isprint.o ft_memset.o ft_memcpy.o ft_memmove.o ft_strlen.o ft_tolower.o
OBJ += ft_toupper.o
HEADER = libft.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cc $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

# TODO: remove 
run:
	cc $(FLAGS) -I$(HEADER) -o test $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all