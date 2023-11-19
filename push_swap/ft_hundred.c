/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/19 05:32:33 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_outmoves(int chsize, int numpos)
{
	if ((chsize - numpos) <= numpos)
		return (chsize - numpos);
	return (numpos);
}

int	ft_takeon(int size, int chsize, int *index, int *stackb)
{
	int	temp;

	temp = 0;
	while (temp < chsize)
	{
		if (index[0] <= chsize)
		{
			ft_pb(size, index, stackb);
			temp += 1;
		}
		else
			ft_ra(size, index);
	}
	return (temp);
}

void	ft_takeout(int size, int chsize, int *index, int *stackb)
{
	int	numpos;

	numpos = 0;
	while (chsize > 0)
	{
		numpos = ft_minnum(size, stackb);
		if (numpos <= chsize / 2)
		{
			while (numpos-- > 0)
				ft_rb(chsize, stackb);
		}
		else
		{
			while (numpos++ < chsize)
				ft_rrb(chsize, stackb);
		}
		if (ft_isorder(size, index) == 0 && index[0] < stackb[0])
			ft_ra(size, index);
		ft_pa(size, stackb, index);
		chsize--;
	}
	ft_ra(size, index);
}
