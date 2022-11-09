/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:03:53 by mafarto-          #+#    #+#             */
/*   Updated: 2022/11/09 17:04:34 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*  *Libresias*  */

# include <unistd.h>
# include <stdarg.h>

/*  *Funciones*  */

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, char *base);
int	ft_strlen(char *str);
#endif