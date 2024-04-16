NAME		:= so_long
MLX_CF		:= -framework OpenGL -framework AppKit
CFLAGS		:= -Wall -Wextra -Werror -Ilib/libft -g
MLX_PATH	:= lib/mlx
LIBFT_PATH	:= lib/libft
FT_PRINTF_PATH	:= lib/printf
INCLUDE 	:= src/so_long.h
SRC 		:= src/main.c\
				src/ft_map.c\
				src/ft_mapcheker.c\
				src/ft_player.c\
				src/ft_textures.c\
				src/ft_closegame.c\
				src/ft_move.c\

OBJ	= $(SRC:.c=.o)

.o: %.c
	$(CC) -c $(CFLAGS) $^

all:$(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	mkdir -p bin
	make -C $(MLX_PATH) 2>/dev/null
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINTF_PATH)
	mv $(MLX_PATH)/libmlx.a bin/
	mv $(LIBFT_PATH)/libft.a bin/
	mv $(FT_PRINTF_PATH)/ft_printf.a bin/
	cc  $(CFLAGS) $(MLX_CF) bin/libmlx.a bin/libft.a bin/ft_printf.a $(SRC) -o $(NAME) 

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf bin
fclean: clean
	rm -f $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re