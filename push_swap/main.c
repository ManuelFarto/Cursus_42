/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:57:27 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/18 17:01:53 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*new;
	char	**trash;
	int		size;

	size = argc;
	if (size <= 1)
		return (0);
	else if (size == 2)
	{
		trash = ft_split(argv[1], 32, &size);
		new = ft_push_swap(size, trash);
		//printf("%s", new);
		ft_free(trash);
		trash = 0;
	}
	else
	{
		new = ft_push_swap(size - 1, &argv[1]);
		//printf("%s", new);
	}
	return (0);
}
