/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:50:52 by mafarto-          #+#    #+#             */
/*   Updated: 2023/06/08 20:15:14 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str, char *stat)
{
	int		readed;
	char	*tmp;

	readed = 1;
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (readed > 0 && ft_comp(stat) == -1)
	{
		readed = read(fd, str, BUFFER_SIZE);
		if (readed == -1)
			return (free(str), NULL);
		str[readed] = '\0';
		tmp = ft_strjoin(stat, str);
		if (stat)
			free(stat);
		stat = tmp;
	}
	return (free(str), stat);
}

char	*ft_cut(int size, char **stat)
{
	char	*tmp;
	char	*stat2;
	int		num;

	num = 0;
	tmp = malloc((size + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (num <= size)
	{
		tmp[num] = stat[0][num];
		num++;
	}
	tmp[num] = '\0';
	stat2 = ft_strdup(&stat[0][size + 1]);
	free(stat[0]);
	stat[0] = stat2;
	return (tmp);
}
