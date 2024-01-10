# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 08:01:15 by mafarto-          #+#    #+#              #
#    Updated: 2024/01/09 16:44:18 by mafarto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
NAME_CLIENT = 	client
NAME_SERVER = 	server

NAME_CLIENT_BONUS = 	client_bonus
NAME_SERVER_BONUS = 	server_bonus

LIBFT		=	libft/libft.a
INC			=	inc/

CC			=	gcc -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_CLIENT	=	client.c 
OBJ_CLIENT	= 	$(SRC_CLIENT:.c=.o)

SRC_SERVER	=	server.c 
OBJ_SERVER	= 	$(SRC_SERVER:.c=.o)

SRC_CLIENT_BONUS	=	client_bonus.c 
OBJ_CLIENT_BONUS	= 	$(SRC_CLIENT_BONUS:.c=.o)

SRC_SERVER_BONUS	=	server_bonus.c 
OBJ_SERVER_BONUS	= 	$(SRC_SERVER_BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
			make -C ./libft

$(NAME_CLIENT):	$(OBJ_CLIENT)
			$(CC) -o $(NAME_CLIENT) $(FLAGS) $(SRC_CLIENT)-I$(INC) $(LIBFT)		

$(NAME_SERVER):	$(OBJ_SERVER)
			$(CC) -o $(NAME_SERVER) $(FLAGS) $(SRC_SERVER)-I$(INC) $(LIBFT)

bonus: $(LIBFT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS):	$(OBJ_CLIENT_BONUS)
			$(CC) -o $(NAME_CLIENT_BONUS) $(FLAGS) $(SRC_CLIENT_BONUS)-I$(INC) $(LIBFT)		

$(NAME_SERVER_BONUS):	$(OBJ_SERVER_BONUS)
			$(CC) -o $(NAME_SERVER_BONUS) $(FLAGS) $(SRC_SERVER_BONUS)-I$(INC) $(LIBFT)

.c.o:
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
			@$(RM) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM)  $(NAME) $(NAME_SERVER) $(NAME_CLIENT)
			@$(RM)  $(NAME) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re:			fclean all

.PHONY:		all clean fclean re libft print