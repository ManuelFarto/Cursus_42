/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:23:38 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/30 21:25:04 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"
#include<stdio.h>

int	ft_conver(va_list ap, char ch)
{
	if (ch == 'c')
	{
		ft_putchar(va_arg(ap, int));
		return (0);
	}
	else if (ch == 's')
	{
		ft_putstr(va_arg(ap, char *));
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
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

int	main()
{
	char	a = 'b';
	char	*str = NULL;
	ft_printf("La letra es: %c vvhg %s \n", a, str);
	printf("La letra es: %c vvhg %s \n", a, str);
	return (0);
}
