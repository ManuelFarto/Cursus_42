/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/13 16:08:14 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_outmoves(int chsize, int numpos)
{
	if (chsize - numpos < numpos)
		return (chsize - numpos);
	return (numpos);
}

void	ft_takeout(int chsize, int numpos, int *index, int *stackb)
{
	int ismin;

	ismin = 0;
	if (numpos == ft_minnum(chsize, stackb))
		ismin = 1;
	if (numpos <= chsize / 2)
	{
		while (numpos-- > 0)
			ft_rrb(chsize, stackb);
	}
	else
	{
		while (numpos++ <= chsize)
			ft_rb(chsize, stackb);
	}
	ft_pa(ft_numsize(index) + ft_numsize(stackb), stackb, index);
	if (ismin == 1)
		ft_ra(ft_numsize(index) + ft_numsize(stackb), index);
}
