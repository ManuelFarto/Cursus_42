/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:01:51 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/20 20:49:00 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

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

char	**ft_split(char const *s, char c)
{
	char			**new;
	unsigned int	i;
	unsigned int	word_start;
	unsigned int	word_nb;

	new = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!new)
		return (0);
	i = 0;
	word_nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			new[word_nb] = ft_substr(s, word_start, i - word_start);
			word_nb++;
			continue ;
		}
		i++;
	}
	new[word_nb] = 0;
	return (new);
}

/* int	ft_strcont(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0)
			i = 0;
		else if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == 0 && s[i] != c))
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
		return (0);
	dst = (char **)malloc((1 + ft_strcont(s, c)) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (s[i] && ft_strcont(s, c) != 0)
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == 0 && s[i - 1] != c))
		{
			dst[j] = ft_substr(s, k, i - k + 1);
			j++;
			k = i + 1;
		}
		i++;
	}
	dst[j] = 0;
	return (dst);
}

int	main(void)
{
	char str[] = "............";
	char c = '.';
	printf("%i", ft_strcont(str, c));
}
 */ 