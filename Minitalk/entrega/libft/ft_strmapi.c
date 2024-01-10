/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:24:24 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/09 13:50:40 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	dst = ft_strdup(s);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = f(i, dst[i]);
		i++;
	}
	return (dst);
}
