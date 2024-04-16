/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:40:27 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/15 20:02:22 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_textures(t_game *game)
{
	int	x;
	int	y;

	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &(x), &(y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &(x), &(y));
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &(x), &(y));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &(x), &(y));
	game->img.coin = mlx_xpm_file_to_image(game->mlx, COIN, &(x), &(y));
}

void	ft_printtextures(t_game *game, int y, int x)
{
	char texture;

	texture = game->map.map[y][x];
	if (texture == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.wall, x * 16, y * 16);
	if ((texture == 'E'|| texture == '0') || (texture == 'P' || texture == 'C'))
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.floor, x * 16, y * 16);
	if (texture == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player, x * 16, y * 16);
	if (texture == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.coin, x * 16, y * 16);
	if (texture == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.exit, x * 16, y * 16);
}

void	ft_save_print(t_game *game)
{
	int	y;
	int	x;

	ft_textures(game);
	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			ft_printtextures(game, y, x);
			x++;
		}
		y++;
	}
}
