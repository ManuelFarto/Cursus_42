/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:59 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/15 21:01:21 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_0(t_game *game, int my, int mx)
{
	if (game->map.map[game->player.y][game->player.x] != 'D')
		game->map.map[game->player.y][game->player.x] = '0';
	else
		game->map.map[game->player.y][game->player.x] = 'E';
	game->map.map[game->player.y + my][game->player.x + mx] = 'P';
	game->player.y += my;
	game->player.x += mx;
	ft_save_print(game);
	ft_printf("moves -> %d\n", game->player.moves++);
}

void	check_collects(t_game *game, int my, int mx)
{
	game->player.tokens--;
	if (game->map.map[game->player.y][game->player.x] != 'D')
		game->map.map[game->player.y][game->player.x] = '0';
	else
		game->map.map[game->player.y][game->player.x] = 'E';
	game->map.map[game->player.y + my][game->player.x + mx] = 'P';
	game->player.y += my;
	game->player.x += mx;
	ft_save_print(game);
	ft_printf("moves -> %d\n", game->player.moves++);
}

void	ft_playercontroller(t_game *game, int my, int mx)
{
	int	py;
	int	px;

	py = game->player.y;
	px = game->player.x;
	if (game->map.map[py + my][px + mx] == '1')
		return ;
	if (game->map.map[py + my][px + mx] == '0')
		return (check_0(game, my, mx));
	if (game->map.map[py + my][px + mx] == 'E' && game->player.tokens == 0)
		return ((void)ft_closegame(game));
	if (game->map.map[py + my][px + mx] == 'C')
		return (check_collects(game, my, mx));
	else
		game->map.map[py][px] = '0';
	if (game->map.map[py + my][px + mx] == 'E')
	{
		game->map.map[game->player.y + my][game->player.x + mx] = 'D';
		game->player.y += my;
		game->player.x += mx;
	}
	ft_save_print(game);
	ft_printf("moves -> %d\n", game->player.moves++);
}

int	ft_axis(int butoon, t_game *game)
{
	if (butoon == Q || butoon == ESC)
		ft_closegame(game);
	else if (butoon == W || butoon == KEY_UP)
		ft_playercontroller(game, -1, 0);
	else if (butoon == S || butoon == KEY_DOWN)
		ft_playercontroller(game, 1, 0);
	else if (butoon == A || butoon == KEY_LEFT)
		ft_playercontroller(game, 0, -1);
	else if (butoon == D || butoon == KEY_RIGHT)
		ft_playercontroller(game, 0, 1);
	return (0);

}
