/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/18 17:47:29 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_outmoves(int chsize, int numpos)
{
	if ((chsize - numpos) <= numpos)
		return (chsize - numpos);
	return (numpos);
}

void	ft_takeout(int chsize, int numpos, int *index, int *stackb)
{
	while (chsize > 0)
	{
		numpos = ft_minnum(ft_numsize(index) + ft_numsize(stackb), stackb);
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
		if (ft_isorder(ft_numsize(index) + ft_numsize(stackb), index)
			== 0 && index[0] < stackb[0])
		{
			ft_ra(ft_numsize(index), index);
		}
		ft_pa(ft_numsize(index) + ft_numsize(stackb), stackb, index);
		// for(int x = 0; x < ft_numsize(index) + ft_numsize(stackb); x++)
			// //printf("conchi %d || stackb %d\n", index[x], stackb[x]);
		chsize--;
	}
	if (chsize == 0)
		ft_ra(ft_numsize(index), index);
}
