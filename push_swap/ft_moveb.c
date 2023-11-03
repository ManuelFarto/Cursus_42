/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:55 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/03 09:39:48 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(int *index)
{
	int	temp;

	temp = index[0];
	index [0] = index[1];
	index[1] = temp;
	write(1, "sb\n", 3);
}

void	ft_rb(int size, int *index)
{
	int	temp;
	int	i;

	temp = index[0];
	i = 1;
	while (size > i)
	{
		index[i - 1] = index[i];
		i++;
	}
	index[size - 1] = temp;
	write(1, "rb\n", 3);
}

void	ft_rrb(int size, int *index)
{
	int	temp;
	int	i;

	temp = index[size - 1];
	i = size - 1;
	while (0 < i)
	{
		index[i] = index[i - 1];
		i--;
	}
	index[0] = temp;
	write(1, "rrb\n", 4);
}

/* void	ft_pb(int size, int *index, int *stackb)
{
	int	temp;
	int	i;

	if (!stackb)
		return ;
	temp = stackb[0];
	i = size - 1;
	while (0 < i)
	{
		index[i] = index[i - 1];
		i--;
	}
	index[0] = temp;
	write(1, "pb\n", 3); */
