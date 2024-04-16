# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 20:11:12 by mafarto-          #+#    #+#              #
#    Updated: 2022/11/12 14:39:00 by mafarto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf.a

INCLUDE = ft_printf.h

CC = gcc

CFLAGS =  -Werror -Wall -Wextra -g

RM = rm -f

SRCS	=	ft_printf.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_strlen.c\
			ft_putpunt.c\

OBJ	= $(SRCS:.c=.o)

.o: %.c
	$(CC) -c $(CFLAGS) $^

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clear fclear re
