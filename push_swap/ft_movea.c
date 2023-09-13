/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:39 by mafarto-          #+#    #+#             */
/*   Updated: 2023/09/13 11:04:19 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(int *index)
{
    int temp;
    
    temp = index[0];
    index [0] = index[1];
    index[1] = temp;
    write(1, "sa\n", 3);
}

void    ft_ra(int size, int *index)
{
    int temp;
    int i;
    
    temp = index[0];
    i = 0;
    while (size - 1 > i)
    {
        index[i] = index[i + 1];
        i++;
    }
    index[size] = temp;
    write(1, "ra\n", 3);
}
