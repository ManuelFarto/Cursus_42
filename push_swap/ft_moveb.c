/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:41:55 by mafarto-          #+#    #+#             */
/*   Updated: 2023/09/13 10:52:08 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sb(int *index)
{
    int temp;
    
    temp = index[0];
    index [0] = index[1];
    index[1] = temp;
    write(1, "sb\n", 3);
}

void    ft_rb(int size, int *index)
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
    write(1, "rb\n", 3);
}

void    ft_rrb(int size, int *index)
{
    int temp;
    int i;
    
    temp = index[size];
    i = size;
    while (size < i)
    {
        index[i] = index[i + 1];
        i--;
    }
    index[size] = temp;
    write(1, "rrb\n", 3);
}
