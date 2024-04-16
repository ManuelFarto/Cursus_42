/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:27:27 by mafarto-          #+#    #+#             */
/*   Updated: 2024/04/16 18:54:58 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapsize(t_game *game)
{
	char	*str;
	int		y;

	str = get_next_line(game->fd);
	game->map.x = ft_strlen(str);
	y = 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(game->fd);
		if (str != NULL)
			y++;
	}
	game->map.y = y;
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y));
	if (!game->map.map)
		ft_error("Error\nMap check error.", game);
	y = 0;
	while (y < game->map.y)
    {
		game->map.map[y] = (char*) malloc(sizeof(char) * (game->map.x));
		if (!game->map.map[y])
			ft_error("Error\nMap check error.", game);
		y++;
	}
}

void	ft_savemap(t_game *game, char *argv)
{
	int i = 0;
	char	*str;

	if (ft_strnstr(argv, ".ber", ft_strlen(argv)) == NULL)
		ft_error("Error\nInvalid file", game);
	game->fd = open(argv, O_RDONLY);
	ft_mapsize(game);
	close(game->fd);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		ft_error("Error\nThere is no map.\n", game);
	str = get_next_line(game->fd);
	if (!game->map.map)
		ft_error("Error\nMap error.\n", game);
	game->map.savedmap = true;
	while (str != NULL)
	{
		game->map.map[i] = str;
		str = get_next_line(game->fd);
		i++;
	}
	free(str);
	close(game->fd);
}
