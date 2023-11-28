/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:57:27 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/23 11:46:07 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**trash;
	int		size;

	size = argc;
	if (size <= 1)
		return (0);
	else if (size == 2)
	{
		trash = ft_split(argv[1], 32, &size);
		ft_push_swap(size, trash);
		ft_free(trash);
		trash = 0;
		return (0);
	}
	else
	{
		ft_push_swap(size - 1, &argv[1]);
		return (0);
	}
	return (0);
}
