/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:54:51 by mafarto-          #+#    #+#             */
/*   Updated: 2022/10/24 16:46:17 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

/* int	ft_intlen(int n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		nb++;
	if (n < 0)
	{
		n *= -1;
		nb++;
	}
	while (n > 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}*/
int	ft_intlen(long m)
{
	int	lens;

	lens = 0;
	if (m <= 0)
		lens = 1;
	while (m != 0)
	{
		lens++;
		m = m / 10;
	}
	return (lens);
}

char	*ft_itoa(long int n)
{
	char	*dst;
	int		len;

	len = ft_intlen(n);
	dst = (char *)malloc(((len) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[len--] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		dst[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (dst);
}

/*int	main()
{
	int	n = -62300000;
	char	*res = ft_itoa(n);

	printf("result: %s\n", res);
	return (0);
}



char	*ft_itoa(long int n)
{
	char	*s;
	int		i;
	long	m;

	m = n;
	i = len(m);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (m == 0)
		s[0] = '0';
	if (m < 0 )
	{
		s[0] = '-';
		m = m * -1;
	}
	while (m > 0)
	{
		s[i] = '0' + (m % 10);
		m = m / 10;
		i--;
	}
	return (s);
}*/