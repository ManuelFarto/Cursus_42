/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:23:38 by mafarto-          #+#    #+#             */
/*   Updated: 2022/11/09 17:10:11 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int	ft_conver(va_list ap, char ch)
{
	if (ch == '%')
		return (ft_putchar(va_arg(ap, int)));
	else if (ch == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (ch == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (ch == 'd')
		return (ft_putnbr(va_arg(ap, int), "0123456789"));
	else if (ch == 'i')
		return (ft_putnbr(va_arg(ap, int), "0123456789"));
	else if (ch == 'x')
		return (ft_putnbr(va_arg(ap, int), "0123456789abcdef"));
	else if (ch == 'X')
		return (ft_putnbr(va_arg(ap, int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_conver(ap, str[i +1]);
			i +=  2;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end (ap);
	return (i);
}

/* int	main()
{
	char	a = 'b';
	char	*str = "hola";
	int		i = -2147483;
	ft_printf("La letra es: %c vvhg %s askdgahsg %i eeeee %x \n", a, str, i, i);
	printf("La letra es: %c vvhg %s askdgahsg %i eeeee %x \n", a, str, i, i);
	return (0);
} */
