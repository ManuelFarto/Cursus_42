/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:27:33 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/16 19:09:59 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.y)
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

void    ft_error(char *str, t_game *game)
{
    ft_printf("%s", str);
    if (game->map.savedmap == true)
		ft_free(game);
    exit(1);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, ft_closegame, game);
	mlx_hook(game->mlx_win, 2, 1, ft_axis, game);
}

int main(int argc, char **argv)
{
    t_game game;

	if (argc != 2)
		ft_error("Error.\n", &game);
    ft_bzero(&game, sizeof(t_game));
	game.map.savedmap = false;
    ft_savemap(&game, argv[1]);
	ft_maperror(&game);
    ft_mapheck(&game);
    ft_findplayer(&game);
    ft_validmap(&game);
	ft_free(&game);
    ft_savemap(&game, argv[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, (game.map.x - 1) * 16, game.map.y * 16,
		"so_long");
	ft_save_print(&game);
	ft_hooks(&game);
	ft_save_print(&game);
	mlx_loop(game.mlx);
		ft_free(&game);
    return (0);
}
