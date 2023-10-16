/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:19 by mafarto-          #+#    #+#             */
/*   Updated: 2023/10/16 12:28:22 by mafarto-         ###   ########.fr       */
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
	ft_pa(size, index, stackb);
	for (int x = 0; x < size; x++)
		printf("Index: %d\n", index[x]);
}

void	ft_alg(int size, int *index)
{
	int	*stackb;

	stackb = malloc(sizeof(int) * size);
	if (!stackb)
		return ;
	ft_bzero(stackb, size);
	if (ft_isorder(size, index) == 1)
		return ;
	else if (size == 2)
		ft_rra(size, index);
	else if (size == 3)
		return (ft_algthree(size, index));
	else if (size == 5)
		return (ft_algfive(size, index, stackb));
}
