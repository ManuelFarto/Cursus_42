/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:55 by mafarto-          #+#    #+#             */
/*   Updated: 2023/05/24 16:27:39 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 25
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

char	*ft_read(int fd, char *str, char *line)
{
	ssize_t	rea;
	char	*tmp;

	rea = read(fd, str, BUFFER_SIZE);
	if (rea <= 0)
		return (0);
	str[rea] = '\0';
	tmp = line;
	free(line);
	line = NULL;
	line = ft_strjoin(tmp, str);
	return (line);
}

int	ft_comper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		str[BUFFER_SIZE + 1];
	static char	*line;
	int			nu;
	ssize_t		rea;

	if (!BUFFER_SIZE)
		return (NULL);
	line = NULL;
	rea = read(fd, str, BUFFER_SIZE);
	if (rea <= 0)
		return (0);
	str[BUFFER_SIZE] = '\0';
	if (!line)
		line = ft_strjoin("", str);
	nu = -1;
	while (ft_comper(line) == 0)
	{
		line = ft_read(fd, str, line);
	}
	return (line);
}

int	main(void)
{
	int	fd;
	//int	fd2;
	int	i = 0;
	char *str;
	//char *str2;
	fd = open("textpru.txt", O_RDWR);
	//fd2 = open("texto2", O_RDWR);
	str = get_next_line(fd);
	printf("\n&%s&\n", str);
	str = get_next_line(fd);
	printf("\n&%s&", str);
	free(str);
	//str2 = get_next_line(fd2);
	//printf("&\n%s&\n", str2);
	//str2 = get_next_line(fd2);
	//printf("&\n%s&\n", str2);
	close(fd);
	//close(fd2);
}

//TO DO: 
// - Primero que te recorte la linea (line) hasta el salto de linea
// - Segundo guardar el resto en una variable estática
