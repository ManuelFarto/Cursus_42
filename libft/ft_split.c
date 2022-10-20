/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:01:51 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/18 19:07:27 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

int	ft_strcont(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == 0 && s[i] != c))
			j++;
	i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	dst = (char **)malloc(1 + ft_strcont(s, c) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || s[i + 1] == 0)
		{
			dst[j] = ft_substr(s, k, i);
			j++;
			k = i + 1;
		}
		else if (s[i] != c)
		{
			dst[j] = ft_substr(s, k, i);
			j++;
			k = i + 1;
		}
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char str[] = ".hola..que...haces.xD";
	char c = '.';
	printf("%i", ft_strcont(str, c));
}*/
