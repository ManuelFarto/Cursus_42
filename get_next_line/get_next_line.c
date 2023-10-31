/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:55 by mafarto-          #+#    #+#             */
/*   Updated: 2023/05/26 19:51:54 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i ++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		n;

	n = 0;
	if (s1 == NULL)
		return (NULL);
	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[n])
	{
		s2[n] = s1[n];
		n++;
	}
	s2[n] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	dstsize;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	dstsize = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i] && s1[i] != '\0')
		dst[i] = s1[i];
	dst[i] = '\0';
	j = -1;
	while (s2[++j] && i + 1 < dstsize && s2[j] != '\0')
		dst[i++] = s2[j];
	dst[i] = '\0';
	return (dst);
}

int	ft_comp(char *stat)
{
	int	cont;

	cont = 0;
	if (!stat)
		return (-1);
	while (stat[cont] && stat[cont] != '\n')
		cont++;
	if (stat[cont] == '\n')
		return (cont);
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*line;
	int			size;

	if (0 >= BUFFER_SIZE || 0 > fd)
		return (NULL);
	str = NULL;
	line = ft_read(fd, str, line);
	if (!line)
		return (NULL);
	size = ft_comp(line);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (size == -1 || (int)ft_strlen(line) == size + 1)
	{
		str = line;
		line = NULL;
		return (str);
	}
	return (ft_cut(size, &line));
}

/* int	main(void)
{
	int	fd;
	int	i = 0;
	char *str;

	fd = open("textpru.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("\nIntento ====> %d\n", ++i);
		printf("returned: %s", str);
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	close(fd);
} */
