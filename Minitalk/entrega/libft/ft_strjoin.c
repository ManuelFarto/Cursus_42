/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:45:04 by mafarto-          #+#    #+#             */
/*   Updated: 2024/01/09 13:50:40 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;

	if (!s1 || !s2)
		return (NULL);
	mem = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, (ft_strlen(s1) + 1));
	ft_strlcat(mem, s2, (ft_strlen(s2) + ft_strlen(s1) + 1));
	return (mem);
}
