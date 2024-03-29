/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:41:04 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/08 16:30:58 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isorder(int size, int *index)
{
	int	i;

	i = 1;
	while (size > i)
	{
		if (index[i] < index[i - 1] && index[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_bzero(int *s, int n, int o)
{
	int	i;

	i = 0;
	while (n > i)
	{
		s[i] = o;
		i++;
	}
}

int	*ft_index(int size, long *nums)
{
	int	*dst;
	int	i;
	int	j;

	dst = malloc(sizeof(int) * size);
	if (dst == NULL)
		return (free(nums), write(2, "Error\n", 6), NULL);
	ft_bzero(dst, size, 1);
	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (nums[i] < nums[j])
				dst[j] += 1;
			else
				dst[i] += 1;
			i++;
		}
		j++;
	}
	free(nums);
	return (dst);
}
