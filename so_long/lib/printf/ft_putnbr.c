/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:52:51 by mafarto-          #+#    #+#             */
/*   Updated: 2022/11/12 14:41:55 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(long long nb, char *base, int *len, char form)
{
	int		b;

	if ((form == 'u' || form == 'x') || (form == 'X'))
		nb = (unsigned int) nb;
	else if (form == 'i' || form == 'd')
		nb = (long)nb;
	b = ft_strlen_print(base);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		*len += 1;
	}
	if (nb > b -1)
		ft_putnbr((nb / b), base, len, form);
	return (ft_putchar(base[nb % b]), *len += 1);
}
