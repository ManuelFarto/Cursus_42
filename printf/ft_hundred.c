/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/26 21:23:57 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

int	ft_outmoves(int size, int numpos)
{
	if (numpos < size / 2)
		return (1);
	return (0);
}

void	ft_takeon(int size, int chsize, int *index, int *stackb)
{
	static int	temp;

	while (temp < chsize)
	{
		if (index[0] <= chsize)
		{
			ft_pb(size, index, stackb);
			temp++;
		}
		else
		{
			ft_ra(size, index);
		}
	}
}

void	ft_takeout(int size, int *index, int *stackb)
{
	int	numpos;
	int	count;

	numpos = 0;
	count = size;
	while (count > 0)
	{
		numpos = ft_minnum(size, stackb);
		if (ft_outmoves(count, numpos) == 1)
		{
			while (numpos-- > 0)
				ft_rb(count, stackb);
		}
		else if (count > 1)
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
