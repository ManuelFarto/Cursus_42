/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:03:53 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/30 21:11:37 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*  *Libresias*  */

# include <unistd.h>
# include <stdarg.h>

/*  *Funciones*  */

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
#endif