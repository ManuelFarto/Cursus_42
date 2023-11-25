/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/25 06:58:04 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

int	ft_outmoves(int size, int chunk, int numpos)
{
	if (numpos < ((size / chunk) / 2))
		return (1);
	else if (numpos < size / chunk)
		return (1);
	return (0);
	
}
// int	ft_minmubs(int chsize, int temp, int *index)
// {
// 	int	i;
// 	int	min;
// 	int	count;

// 	i = 0;
// 	count = size + 1;
// 	min = size;
// 	while (i < size)
// 	{
// 		if (index[i] == 0)
// 			return (min);
// 		if ((index[i] < count))
// 		{
// 			count = index[i];
// 			min = i;
// 		}
// 		i++;
// 	}
// 	return (min);

/* int	ft_takeon(int size, int chsize, int *index, int *stackb)
{
	int	temp;

	temp = 0;
	while (temp < chsize)
	{

	}
	return (temp);
} */

void	ft_takeout(int size, int chunk, int *index, int *stackb)
{
	int	numpos;
	int	count;

	numpos = 0;
	count = size;

	while (count > 0)
	{
		numpos = ft_minnum(size, stackb);
		if (ft_outmoves(size, chunk, numpos) == 1)
		{
			while (numpos-- > 0)
				ft_rb(count, stackb);
		}
		else
		{
			while (numpos++ < count)
				ft_rrb(count, stackb);
		}
		if (ft_isorder(size, index) == 0 && index[0] < stackb[0])
			ft_ra(size, index);
		ft_pa(size, stackb, index);
		count--;
	}
	ft_ra(size, index);
}
