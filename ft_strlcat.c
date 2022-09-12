/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:53:36 by mafarto-          #+#    #+#             */
/*   Updated: 2022/09/10 20:25:46 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	
	i = -1;
	j = ft_strlen(dst);
	if (dstsize <= j)
		return (ft_strlen(src) + dstsize);
	while (src[++i] && j + 1 < dstsize)
		dst[j++] = src[i];
	dst[j] = '\0';
	return (j + ft_strlen(&src[i]));
}
