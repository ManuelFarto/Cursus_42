/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:50:16 by mafarto-          #+#    #+#             */
/*   Updated: 2023/10/16 10:28:19 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_safe_num(int size, char **argv)
{
	long	*nums;
	int		cont;
	int		i;

	cont = 0;
	i = 0;
	nums = malloc(sizeof(long) * size);
	if (!nums)
		return (0);
	while (argv[cont])
	{
		nums[i] = ft_atol(argv[cont]);
		cont++;
		i++;
	}
	return (nums);
}

void	*ft_push_swap(int size, char **argv)
{
	int		cont;
	long	*nums;
	int		*index;

	cont = 0;
	while (argv[cont])
	{
		if (ft_numerror(argv[cont]) == 1)
			cont++;
		else
			return (write(2, "Error\n", 6), "");
	}
	if (ft_norep(argv) == 0)
		return (write(2, "Error\n", 6), "");
	nums = ft_safe_num(size, argv);
	if (ft_numover(nums, size) == 0)
		return (free(nums), write(2, "Error\n", 6), "");
	index = ft_index(size, nums);
	ft_alg(size, index);
	free(index);
	return ("");
}
