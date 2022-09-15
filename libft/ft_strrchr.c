/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:41 by mafarto-          #+#    #+#             */
/*   Updated: 2022/09/15 18:19:12 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return (&s[i]);
	while (s[--i] && i > 0)
	{
		if (s[i] == (char)c)
			return (&s[i]);
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}
