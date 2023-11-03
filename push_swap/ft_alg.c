/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:19 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/03 13:07:01 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algthree(int size, int *index)
{
	if (index[0] == 1 && index[1] == 0)
		ft_sa (index);
	else if (index[0] == 2 && index[1] == 1)
	{
		ft_sa(index);
		ft_rra(size, index);
	}
	else if (index[0] == 2 && index[1] == 0)
		ft_ra(size, index);
	else if (index[0] == 0 && index[1] == 2)
	{
		ft_sa(index);
		ft_ra(size, index);
	}
	else
	{
		ft_rra(size, index);
	}
}

void	ft_algfive(int size, int *index, int *stackb)
{
	int	i;
	int	min;

	i = 0;
	min = 1;
	while (i < size)
	{
		if (index[i] <= min)
			min = index[i];
		i++;
	}
	if (i <= size)
	{
		while (i > 0)
		{
			ft_ra(size, index);
		}
	}
	else
	{
		i = size - i;
		while (i > 0)
		{
			ft_rra(size, index);
		}
	}
}

void	ft_alg(int size, int *index)
{
	int	*stackb;

	stackb = malloc(sizeof(int) * size);
	if (!stackb)
		return ;
	ft_bzero(stackb, size, 0);
	if (ft_isorder(size, index) == 1)
		return ;
	else if (size == 2)
		ft_rra(size, index);
	else if (size == 3)
		return (ft_algthree(size, index));
	else if (size == 5)
		return (ft_algfive(size, index, stackb));
}
