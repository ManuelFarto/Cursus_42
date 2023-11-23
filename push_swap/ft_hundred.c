/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/23 13:15:07 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

int	ft_outmoves(int chsize, int numpos)
{
	if ((chsize - numpos) <= numpos)
		return (chsize - numpos);
	return (numpos);
}

/* int	ft_takeon(int size, int chsize, int *index, int *stackb)
{
	int	temp;

	temp = 0;
	while (temp < chsize)
	{
		
	}
	return (temp);
} */

void	ft_takeout(int size, int *index, int *stackb)
{
	int	numpos;
	int	count;

	numpos = 0;
	count = size;
	while (count > 0)
	{
		numpos = ft_minnum(size, stackb);
		if (numpos <= size / 2)
		{
			while (numpos-- > 0)
				ft_rb(count, stackb);
		}
		else
		{
			while (numpos++ < count)
			{
				ft_rrb(count, stackb);
			}
		}
		if (ft_isorder(size, index) == 0 && index[0] < stackb[0])
			ft_ra(size, index);
		ft_pa(size, stackb, index);
		count--;
	}
	ft_ra(size, index);
}
