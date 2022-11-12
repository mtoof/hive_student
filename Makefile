# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:50:23 by mtoof             #+#    #+#              #
#    Updated: 2022/11/12 01:17:06 by sepehr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c	\
		ft_isprint.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlen.c ft_tolower.c	\
		ft_toupper.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strnstr.c ft_strrchr.c	\
		ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_calloc.c ft_atoi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c	\
		ft_putendl_fd.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_striteri.c \
		ft_split.c
OBJ = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o	\
		ft_isprint.o ft_memset.o ft_memcpy.o ft_memmove.o ft_strlen.o ft_tolower.o	\
		ft_toupper.o ft_memcmp.o ft_memchr.o ft_strncmp.o ft_strnstr.o ft_strrchr.o	\
		ft_strchr.o  ft_strlcat.o ft_strlcpy.o ft_strdup.o ft_calloc.o ft_atoi.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_substr.o ft_strjoin.o	\
		ft_putendl_fd.o ft_strtrim.o ft_strmapi.o ft_itoa.o ft_striteri.o \
		ft_split.o
HEADER = libft.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	
$(NAME):
	cc $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
