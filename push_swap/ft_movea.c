/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:39 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/03 12:02:09 by mafarto-         ###   ########.fr       */
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
		i++;
	}
	index[size - 1] = temp;
	write(1, "ra\n", 3);
}

void	ft_rra(int size, int *index)
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
	write(1, "rra\n", 4);
}

void	ft_pa(int size, int *stackb, int *index)
{
	int	temp;
	int	i;
	int	temp2;

	if (!index)
		return ;
	temp = index[0];
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
