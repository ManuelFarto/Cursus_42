# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 08:01:15 by mafarto-          #+#    #+#              #
#    Updated: 2024/01/09 08:01:41 by mafarto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
NAME_CLIENT = 	client
NAME_SERVER = 	server
LIBFT		=	libft/libft.a
INC			=	inc/

CC			=	gcc -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_CLIENT	=	client.c 
OBJ_CLIENT	= 	$(SRC_CLIENT:.c=.o)

SRC_SERVER	=	server.c 
OBJ_SERVER	= 	$(SRC_SERVER:.c=.o)

# COLORS

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_SERVER) $(OBJ_CLIENT)
			@$(CC) -o $(NAME_CLIENT) $(FLAGS) $(SRC_CLIENT)-I$(INC) $(LIBFT)
			@echo "$(GREEN)CLIENT COMPILED SUCCESFUL!$(DEF_COLOR)"			
			@$(CC) -o $(NAME_SERVER) $(FLAGS) $(SRC_SERVER)-I$(INC) $(LIBFT)
			@echo "$(GREEN)SERVER COMPILED SUCCESFUL!$(DEF_COLOR)"
			
$(LIBFT):
			@make -C ./libft

.c.o:
			@echo "$(BLUE)COMPILING... $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM)  $(NAME) $(NAME_SERVER) $(NAME_CLIENT)
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_CLIENT) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_SERVER) REMOVED!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft print