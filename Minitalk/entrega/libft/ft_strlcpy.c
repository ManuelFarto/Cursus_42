/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:25:45 by mafarto-          #+#    #+#             */
/*   Updated: 2022/09/09 20:13:17 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (src == NULL || dst == NULL)
		return (ft_strlen(src));
	if (dstsize != 0)
	{
		while (src[++i] && --dstsize > 0)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
