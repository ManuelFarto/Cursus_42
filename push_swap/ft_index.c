/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:41:04 by mafarto-          #+#    #+#             */
/*   Updated: 2023/09/13 10:29:49 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isorder(int size, int *index)
{
	int	i;
	
	i = 0;
	while (size > i)
	{
		if (i != index[i])
			return (0);
		i++;
	}	
	return (1);
}

void	ft_bzero(int *s, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		s[i] = -1;
		i++;
	}
}

int	*ft_index(int size, long *nums)
{
	int	*dst;
	int	i;
	int	j;
	int min;

	dst = malloc(sizeof(int) * size);
	if (dst == NULL)
		return (free(nums), write(2, "Error\n", 6), NULL);
	ft_bzero(dst, size);
	j = 0;
	while (j < size)
	{
		min = 0;
		i = 0;
		while (i < size)
		{
			if (nums[i] < nums[min] && dst[i] == -1)
				min = i;
			i++;
		}
		dst[min] = j;
		j++;
	}
	free(nums);
	return (dst);
}
