/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:16:44 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/15 20:57:14 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_findplayer(t_game *game)
{
	int	playerY;
	int	playerX;

	playerY = 0;
	while (playerY < game->map.y - 1)
	{
		playerX = 0;
		while (playerX < game->map.x - 1)
		{
			if (game->map.map[playerY][playerX] == 'P')
			{
				game->player.x = playerX;
				game->player.y = playerY;
				return (ft_balloon(game, playerY, playerX), 0);
			}
			playerX++;
		}
		playerY++;
	}
	return (1);
}

void	ft_validmap(t_game *game)
{
	if (game->player.c_collects != game->player.tokens)
		ft_error("Error\nThe map is not valid.\n", game);
	if(!game->player.exit)
		ft_error("Error\nThe map is not valid.\n", game);
}
