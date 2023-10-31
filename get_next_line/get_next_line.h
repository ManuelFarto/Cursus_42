/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:50 by mafarto-          #+#    #+#             */
/*   Updated: 2023/06/08 20:02:37 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* *Librerias* */

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/* *Funciones* */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_comp(char *stat);
char	*ft_read(int fd, char *str, char *stat);
char	*ft_cut(int size, char **stat);
char	*get_next_line(int fd);
#endif
