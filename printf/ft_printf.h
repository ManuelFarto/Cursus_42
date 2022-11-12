/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:03:53 by mafarto-          #+#    #+#             */
/*   Updated: 2022/11/12 12:08:24 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*  *Libresias*  */

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/*  *Funciones*  */

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long long int nb, char *base, int *len, char form);
int	ft_strlen(char *str);
#endif