/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:19 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/19 05:58:27 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_algthree(int size, int *index)
{	
	if (index[0] - index[1] == 1 || (index[0] - index[1] == -2))
		ft_sa(index);
	if (index[0] - index[1] == 2 && ft_isorder(size, index) == 0)
		ft_ra(size, index);
	if (index[0] - index[1] == -1 && ft_isorder(size, index) == 0)
		ft_rra(size, index);
}

void	ft_algfive(int size, int *index, int *stackb)
{
	int	min;
	int	j;
	int	temp;

	j = 0;
	temp = 0;
	while ((j != 2 && size == 5) || (j != 1 && size == 4))
	{
		min = ft_minnum(size, index);
		if (min <= 1)
			ft_cheatingtool(size, index, min);
		else
			ft_cheatingtool2(size, index, min);
		if (ft_isorder(size, index) == 0)
		{
			ft_pb(size, index, stackb);
			temp++;
		}
		j++;
		min = 0;
	}
	if (ft_isorder(size, index) == 0)
		ft_algthree(3, index);
	while (temp-- != 0)
		ft_pa(size, stackb, index);
}

void	ft_algbig(int size, int *index, int *stackb, int chunk)
{
	int	chsize;
	int	temp;

	chsize = size / chunk;
	temp = ft_takeon(size, chsize, index, stackb);
	ft_takeout(size, chsize, index, stackb);
	while (temp < size)
	{
		ft_pb(size, index, stackb);
		temp++;
	}
	if (size % 2 != 0)
		ft_takeout(size, chsize + 1, index, stackb);
	else
		ft_takeout(size, chsize, index, stackb);
}

void	ft_alg(int size, int *index)
{
	int	*stackb;

	stackb = malloc(sizeof(int) * size);
	if (!stackb)
		return ;
	ft_bzero(stackb, size, 0);
	if (ft_isorder(size, index) == 1)
		return (free(stackb));
	else if (size == 2)
		ft_rra(size, index);
	else if (size == 3)
		return (free(stackb), ft_algthree(size, index));
	else if (size == 4 || size == 5)
		return (ft_algfive(size, index, stackb), free(stackb));
	else if (size > 5 && size <= 100)
		return (ft_algbig(size, index, stackb, 2), free(stackb));
	else
		return (ft_algbig(size, index, stackb, 2), free(stackb));
}
