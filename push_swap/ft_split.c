/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:26:03 by mafarto-          #+#    #+#             */
/*   Updated: 2023/08/22 19:31:50 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	if (j < start)
		return (ft_strdup(""));
	if (len > j)
		len = j;
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			count++;
			continue ;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c, int *size)
{
	char			**new;
	unsigned int	i;
	unsigned int	word_start;

	new = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!new)
		return (0);
	i = 0;
	*size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			new[*size] = ft_substr(s, word_start, i - word_start);
			*size += 1;
			continue ;
		}
		i++;
	}
	new[*size] = 0;
	return (new);
}
