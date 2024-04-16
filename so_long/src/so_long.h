/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:27:40 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/15 20:02:45 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* *Librerias* */

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# define WALL "textures/wall.xpm"
# define FLOOR "textures/flor.xpm"
# define PLAYER "textures/player.xpm"
# define EXIT "textures/dor.xpm"
# define COIN "textures/coin.xpm"
# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_map
{
	char		**map;
	int			    x;
	int			    y;
	int			    player;
	int			    count;
	bool		savedmap;
}			    	t_map;

typedef struct s_player
{
	int			    x;
	int			    y;
	int			    tokens;
	int			    c_collects;
	int		    	moves;
	bool		exit;
}				    t_player;

typedef struct s_image
{
	void		*coin;
	void		*player;
	void		*wall;
	void		*floor;
	void		*exit;
}				    t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			fd;
	t_map		map;
	t_image		img;
	t_player	player;
}				    t_game;

void	ft_savemap(t_game *game, char *argv);
void	ft_error(char *str, t_game *game);
void	ft_maperror(t_game *game);
void	ft_mapheck(t_game *game);
void	ft_balloon(t_game *game, int y, int x);
int		ft_findplayer(t_game *game);
void	ft_validmap(t_game *game);
void	ft_save_print(t_game *game);
int		ft_closegame(t_game *game);
void	ft_free(t_game *game);
int		ft_axis(int butoon, t_game *game);
#endif
