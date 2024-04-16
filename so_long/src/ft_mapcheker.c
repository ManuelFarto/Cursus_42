/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:56:47 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/15 21:46:09 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_balloon(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
		return ;
	if (game->map.map[y][x] == 'C')
		game->player.tokens++;
	if (game->map.map[y][x] == 'E')
		game->player.exit = true;
	game->map.map[y][x] = 'F';
	ft_balloon(game, y + 1, x);
	ft_balloon(game, y - 1, x);
	ft_balloon(game, y, x + 1);
	ft_balloon(game, y, x - 1);
}

void	ft_invalidchar(t_game *game, char c)
{
	if (c == 'C')
		game->player.c_collects++;
	if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
		ft_error("Error\nIncorect char in map.\n", game);
}

void	ft_mapheck(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x-1 && (y == 0 || y == game->map.y - 1))
		{
			if (game->map.map[y][x] != '1')
				ft_error("Error\nThe map is open.\n", game);	
			x++;
		}
		if ((game->map.map[y][0] != '1' &&
			game->map.map[game->map.y - 1][game->map.x - 1] != '1') ||
			(int)ft_strlen(game->map.map[game->map.y - 1]) >= game->map.x)
			ft_error("Error\nThe map is opene.", game);
		y++;
	}
}

void	ft_charerror(int P, int E, int i, t_game *game)
{
	if (P > 1)
		ft_error("Error\nToo many player characters.", game);
	if (E > 1)
		ft_error("Error\nToo many exit characters.", game);
	if (i == game->map.y - 1 && P < 1)
		ft_error("Error\nThere are no player characters.", game);
	if (i == game->map.y - 1 && E < 1)
		ft_error("Error\nThere are no exit characters.", game);
}

void	ft_maperror(t_game *game)
{
	int i;
	int	j;
	int	P;
	int	E;

	i = -1;
	P = 0;
	E = 0;
	while (i++ < game->map.y - 1)
	{
		j = -1;
		while (j++ < game->map.x - 1)
		{
			if (game->map.map[i][j] == 'P')
				P++;
			if (game->map.map[i][j] == 'E')
				E++;
			if (j < game->map.x - 1)
				ft_invalidchar(game, game->map.map[i][j]);
		}
		ft_charerror(P, E, i, game);
		if (((int)ft_strlen(game->map.map[i]) != game->map.x) &&
			(int)ft_strlen(game->map.map[game->map.y - 1]) != game->map.x - 1)
			ft_error("Error\nIncorect line size.\n", game);
	}
}
