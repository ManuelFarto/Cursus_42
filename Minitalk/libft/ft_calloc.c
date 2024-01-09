/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:58:05 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/04 19:34:50 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mal;

	mal = malloc(count * size);
	if (mal != NULL)
		ft_bzero(mal, (count * size));
	return (mal);
}
