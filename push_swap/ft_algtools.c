/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algtools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:07 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/19 05:05:01 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minnum(int size, int *index)
{
	int	i;
	int	min;
	int	temp;

	i = 0;
	temp = size + 1;
	min = size;
	while (i < size)
	{
		if (index[i] == 0)
			return (min);
		if ((index[i] < temp))
		{
			temp = index[i];
			min = i;
		}
		i++;
	}
	return (min);
}

int	ft_maxnum(int chsize, int *index)
{
	int	i;
	int	max;
	int	temp;

	i = 0;
	temp = chsize;
	max = 0;
	while (i < chsize)
	{
		if (index[i] == temp)
		{
			max = i;
		}
		i++;
	}
	return (max);
}

void	ft_cheatingtool(int size, int *index, int min)
{
	int	i;

	i = 0;
	while (i < min)
	{
		ft_ra(size, index);
		i++;
	}
}

void	ft_cheatingtool2(int size, int *index, int min)
{
	while (min < size)
	{
		ft_rra(size, index);
		min++;
	}
}

int	ft_numsize(int *index)
{
	int	size;

	size = 0;
	while (index[size] != 0)
		size++;
	return (size);
}
