# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 16:45:09 by mafarto-          #+#    #+#              #
#    Updated: 2023/09/13 10:42:05 by mafarto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCLUDE = push_swap.h

CC = gcc

CFLAGS =  -Werror -Wall -Wextra -g3 -fsanitize=address

CCLEAR = clear

RM = rm -f

WHT = \033[1;37m

SRCS	= main.c\
		  ft_error.c\
		  push_swap.c\
		  ft_split.c\
		  ft_atol.c\
		  ft_free.c\
		  ft_index.c\
		  ft_alg.c\
		  ft_movea.c\
		  ft_moveb.c\

OBJ	= $(SRCS:.c=.o)

.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	$(CCLEAR)
	@echo "$(WHT)Push swap is ready."

clean:
	$(RM) $(OBJ)
	$(CCLEAR)
	@echo "$(WHT)Removing OBJ..."

fclean: clean
	$(RM) $(NAME)
	$(CCLEAR)
	@echo "$(WHT)Removing ALL..."

re: fclean all

.PHONY: all clear fclear re