/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:41 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/12 15:40:52 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (s[--i] && i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
