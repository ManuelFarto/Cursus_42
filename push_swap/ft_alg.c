/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:19 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/08 16:32:41 by mafarto-         ###   ########.fr       */
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
	int	count;
	int	numpos;

	count = 0;
	if (chunk < 2)
		chunk = 2;
	chsize = size / chunk;
	temp = chsize;
	while (count < chunk)
	{
		if (size % 2 != 0 && count + 1 == chunk)
		{
			chsize = size;
		}
		while (temp > 0)
		{
			numpos = ft_minmubs(temp, size, index);
			printf("%d\n", numpos);
			if (ft_outmoves(chsize, chunk, numpos) == 1)
			{
				while (numpos-- >= 0)
					ft_ra(count, index);
			}
			else
			{
				while (numpos++ <= count)
					ft_rra(count, index);
			}
			if (index[0] <= chsize)
			{
				ft_pb(size, index, stackb);
				temp--;
			}
		}
		chsize += size / chunk;
		temp = size / chunk;
		count++;
	}
	ft_takeout(size, chunk, index, stackb);
	/* for (int x = 0; x < size; x++)
		printf("index >>> %d || stackb >>> %d\n", index[x], stackb[x]); */
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
		return (ft_algbig(size, index, stackb, size / 25), free(stackb));
	else
		return (ft_algbig(size, index, stackb, size / 50), free(stackb));
}
