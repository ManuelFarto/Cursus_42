# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 12:43:31 by mafarto-          #+#    #+#              #
#    Updated: 2022/09/28 16:55:57 by mafarto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

INCLUDE = libft.h

CC = gcc

CFLAGS =  -Werror -Wall -Wextra -g

RM = rm -f

SRCS	= ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_strlen.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strncmp.c\
		  ft_strnstr.c\
		  ft_atoi.c\
		  ft_memset.c\
		  ft_bzero.c\
		  ft_memcpy.c\
		  ft_memmove.c\

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
