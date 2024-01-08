/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/26 19:14:19 by mafarto-         ###   ########.fr       */
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

int	ft_minmubs(int maxsize, int size, int *index)
{
	int	cn;
	int	cost_curr;
	int	cost_last;

	cn = 0;
	cost_last = size / 2;
	cost_curr = size / 2;
	while (cn++ < size / 2)
	{
		if (index[cn] <= maxsize)
		{
			cost_curr = cn;
			break ;
		}
	}
	cn = size;
	while (cn-- > size / 2)
	{
		if (index[cn] <= maxsize)
		{
			cost_last = cn;
			printf("last %d\n", cn);
			break ;
		}
	}
	printf("curr %d || last %d\n", cost_curr, (size - cost_last));
	if (cost_curr <= (size - cost_last))
		return (cost_curr);
	return (cost_last);
}

/* int	ft_takeon(int size, int chsize, int *index, int *stackb)
{
	int	temp;

	temp = 0;
	while (temp < chsize)
	{
		numpos = ft_minmubs(temp, chsize, size - (chunk - count), index);
		if (ft_outmoves(size, chunk, numpos) == 1)
		{
			while (numpos-- > 0)
				ft_ra(count, index);
		}
		else
		{
			while (numpos++ < count)
				ft_rra(count, index);
		}
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
