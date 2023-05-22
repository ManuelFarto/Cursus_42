/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:55 by mafarto-          #+#    #+#             */
/*   Updated: 2023/05/22 18:22:11 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
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
/* char	*ft_read()
{
	
} */

char	*get_next_line(int fd)
{
	char		str[256];
	char static	*line;
	int			nu;
	ssize_t		rea;
	char		*tmp;

	if (!BUFFER_SIZE)
		return (NULL);
	line = NULL;
	rea = read(fd, str, BUFFER_SIZE);
	if (rea <= 0)
		return (0);
	str[BUFFER_SIZE] = '\0';
	line = ft_strjoin("", str);
	nu = -1;
	while (line[++nu] != '\n')
	{
		rea = read(fd, str, BUFFER_SIZE);
		if (rea <= 0)
			break ;
		str[rea] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, str);
		free(tmp);
	}
	return (line);
}

int	main(void)
{
	int	fd;
	int	fd2;
	int	i = 0;
	char *str;
	char *str2;
	fd = open("textpru", O_RDWR);
	fd2 = open("texto2", O_RDWR);
	printf("\n%s\n\n", "hola");
	while (i != 4)
	{
		printf("Numero reps: %i\n", i + 1);
		str = get_next_line(fd);
		printf("&\n%s&\n", str);
		str2 = get_next_line(fd2);
		printf("&\n%s&\n", str2);
		i++;
		free(str);
		free(str2);
	}
	close(fd);
	close(fd2);
}
