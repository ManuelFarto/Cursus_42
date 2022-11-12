/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:23:38 by mafarto-          #+#    #+#             */
/*   Updated: 2022/11/12 12:12:17 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int	ft_conver(va_list ap, char ch)
{
	int	len;

	len = 0;
	if (ch == '%')
		len += ft_putchar('%');
	else if (ch == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (ch == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (ch == 'd')
		ft_putnbr(va_arg(ap, int), "0123456789", &len, 'd');
	else if (ch == 'i')
		ft_putnbr(va_arg(ap, int), "0123456789", &len, 'i');
	else if (ch == 'x')
		ft_putnbr(va_arg(ap, int), "0123456789abcdef", &len, 'x');
	else if (ch == 'X')
		ft_putnbr(va_arg(ap, int), "0123456789ABCDEF", &len, 'X');
	else if (ch == 'p')
	{
		ft_putnbr(va_arg(ap, unsigned long long int),
			"0123456789abcdef", &len, 'p');
	}
	else if (ch == 'u')
		ft_putnbr(va_arg(ap, int), "0123456789", &len, 'u');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_conver(ap, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end (ap);
	return (len);
}

/* int	main()
{
	char	a = '0';
	char	*str = "hola";
	int		len, len3;
	int		i = -2147481;
	len = ft_printf("hola %c", a);
	len3 = printf("%c \n l", a);
	printf("%d y %d\n", len, len3);
	printf("Exa: %llx", 18446744073709537093);
	printf("El puntero es: %p \n", (void *)-14523);
	ft_printf("El puntero es: %p", (void *)-14523);
	return (0);
} */
