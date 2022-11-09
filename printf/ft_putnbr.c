/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:52:51 by mafarto-          #+#    #+#             */
/*   Updated: 2022/11/09 17:04:55 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(int n, char *base)
{
	int		b;
	long	nb;

	if (ft_strlen(base) == 16)
		nb = (unsigned int) n;
	else
		nb = n;
	b = ft_strlen(base);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > ft_strlen(base) -1)
	{
		ft_putnbr((nb / b), base);
	}
	return (ft_putchar(base[nb % b]));
}
