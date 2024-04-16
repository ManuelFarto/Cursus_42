/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closegame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:15:07 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/16 19:21:20 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"so_long.h"


int	ft_closegame(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.player);
	ft_free(game);
	//system("leaks so_long");
	exit(EXIT_SUCCESS);
}