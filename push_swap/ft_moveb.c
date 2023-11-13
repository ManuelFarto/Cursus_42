/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:55 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:29 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(int *stackb)
{
	int	temp;

	temp = stackb[0];
	stackb[0] = stackb[1];
	stackb[1] = temp;
	write(1, "sb\n", 3);
}

void	ft_rb(int size, int *stackb)
{
	int	temp;
	int	i;

	temp = stackb[0];
	i = 1;
	while (size > i)
	{
		stackb[i - 1] = stackb[i];
		if (i == size - 1 || stackb[i + 1] == 0)
			stackb[i] = temp;
		i++;
	}
	write(1, "rb\n", 3);
}

void	ft_rrb(int size, int *stackb)
{
	int	temp;
	int	i;

	i = size - 1;
	while (i > 0)
	{
		if (stackb[i] != 0)
		{
			temp = stackb[i];
			break ;
		}
		i--;
	}
	i = size - 1;
	while (0 < i)
	{
		stackb[i] = stackb[i - 1];
		i--;
	}
	stackb[0] = temp;
	write(1, "rrb\n", 4);
}

void	ft_pb(int size, int *index, int *stackb)
{
	int	i;
	int	temp2;

	if (!stackb)
		return ;
	temp2 = index[0];
	i = 0;
	while ((size - 1) > i)
	{
		index[i] = index[i + 1];
		i++;
	}
	i = size - 1;
	while (0 < i)
	{
		stackb[i] = stackb[i - 1];
		i--;
	}
	index[size - 1] = 0;
	stackb[0] = temp2;
	write(1, "pb\n", 3);
}
