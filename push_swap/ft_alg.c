/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:19 by mafarto-          #+#    #+#             */
/*   Updated: 2023/11/10 03:04:27 by mafarto-         ###   ########.fr       */
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

int	ft_minnum(int size, int *index, int times)
{
	int i;
	int	min;
	int	temp;

	i = 0;
	temp = size;
	min = size;
	while (i < size)
	{
		if ((index[i] < temp) && (index[i] > times))
		{
			temp = index[i];
			min = i;
		}
		i++;
	}
	return (min);
}

void	ft_toend(int size, int *index)
{
	int	num;

	num = ft_minnum(size - 1, index, -1);
	while (size > num)
	{
		index[num - 1] = index[num];
		num++;
	}
	index[size - 1] = 0;
}

void	ft_algfive(int size, int *index, int *stackb)
{
	int	min;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while ((j != 2 && size == 5) || (j != 1 && size == 4))
	{
		min = ft_minnum(size, index, j);
		if (min <= 1 + j)
		{
			while (i < min)
			{
				ft_ra(size, index);
				i++;
			}
		}
		else
		{
			while (min < size - 1)
			{
				ft_rra(size, index);
				min++;
			}
		}
		if (ft_isorder(size, index) == 0)
			ft_pb(size, index, stackb);
		for (int x = 0; x < size; x++)
			printf("Index %d\n", index[x]);
		j++;
		min = 0;
	}
	ft_toend(size, index);
	if (ft_isorder(size, index) == 0)
		ft_algthree(3, index);
	while (j-- != 0)
		ft_pa(size, stackb, index);
	for (int x = 0; x < size; x++)
		printf("Resultado1 %d  || %d\n", index[x], stackb[x]);
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
		return (free(stackb), ft_algthree(size, index));
	else if (size == 5 || size == 4)
		return (ft_algfive(size, index, stackb), free(stackb));
	free(index);
	free(stackb);
}
