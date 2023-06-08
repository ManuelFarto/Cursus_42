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

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i])
		i ++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	dstsize;
	size_t	i;

	i = -1;
	dstsize = ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1;
	s2 = malloc((ft_strlen(s1, 0) + 1));
	if (s1 == NULL)
		return (NULL);
	if (dstsize != 0)
	{
		while (s1[++i] && --dstsize > 0)
			s2[i] = s1[i];
		s2[i] = '\0';
	}
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
		return ((char *)s2);
	dst = (char *)malloc((ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1)
			* sizeof(char));
	dstsize = (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1) * sizeof(char);
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

char	*ft_read(int fd, char *str, char *line)
{
	ssize_t	rea;
	char	*tmp;

	rea = read(fd, str, BUFFER_SIZE);
	if (rea <= 0)
		return (0);
	str[rea] = '\0';
	tmp = line;
	if (!line)
	{
		return (ft_strdup(str));
	}
	line = ft_strjoin(tmp, str);
	/* printf("line >>>> %s", line); */
	return (line);
}

int	ft_comper(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		str[BUFFER_SIZE + 1];
	static char	*line;
	ssize_t		rea;
	char		*tmp;

	if (!BUFFER_SIZE)
		return (NULL);
	str[BUFFER_SIZE] = '\0';
	while (1)
	{
		line = ft_read(fd, str, line);
		/* printf("\nline gnl>>>>> %s\n", line); */
		if (ft_comper(line) > 1)
		{
			tmp = ft_strdup(line);
			break ;
		}
	}
	return (tmp);
}

int	main(void)
{
	int	fd;
	int	i = 0;
	char *str;

	fd = open("textpru.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("\nIntento ====> %d\n", ++i);
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
	}


	close(fd);
}
