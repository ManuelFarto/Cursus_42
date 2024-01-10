/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:37:56 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/09 13:50:40 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
