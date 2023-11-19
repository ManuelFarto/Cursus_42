/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:39 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/19 02:46:23 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *index)
{
	int	temp;

	temp = index[0];
	index [0] = index[1];
	index[1] = temp;
	write(1, "sa\n", 3);
}

void	ft_ra(int size, int *index)
{
	int	temp;
	int	i;

	temp = index[0];
	i = 1;
	while (size > i)
	{
		index[i - 1] = index[i];
		if (i == size - 1 || index[i + 1] == 0)
		{
			index[i] = temp;
			break ;
		}
		i++;
	}
	write(1, "ra\n", 3);
}

void	ft_rra(int size, int *index)
{
	int	temp;
	int	i;

	i = size - 1;
	while (i > 0)
	{
		if (index[i] != 0)
		{
			temp = index[i];
			break ;
		}
		i--;
	}
	while (0 < i)
	{
		index[i] = index[i - 1];
		i--;
	}
	index[0] = temp;
	write(1, "rra\n", 4);
}

void	ft_pa(int size, int *stackb, int *index)
{
	int	i;
	int	temp2;

	if (!index)
		return ;
	temp2 = stackb[0];
	i = 0;
	while ((size - 1) > i)
	{
		stackb[i] = stackb[i + 1];
		i++;
	}
	i = size - 1;
	while (0 < i)
	{
		index[i] = index[i - 1];
		i--;
	}
	stackb[size - 1] = 0;
	index[0] = temp2;
	write(1, "pa\n", 3);
}
