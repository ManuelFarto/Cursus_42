/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafarto- <mafarto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:46:25 by mafarto-          #+#    #+#             */
/*   Updated: 2023/09/04 16:50:27 by mafarto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_isalnum(char c)
{
	if ((c >= 48 && c <= 57) || (c == 43 || c == 45))
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && n -1 > i)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_norep(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
    {
        j = i + 1;
        while (nums[j])
        {
            if (ft_strncmp(nums[i], nums[j], ft_strlen(nums[i])) == 0 &&
					ft_strlen(nums[i]) == ft_strlen(nums[j]))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int ft_numerror(char *nums)
{
	int cont;
	
	cont = 0;
	while (ft_isalnum(nums[cont]) == 1 && nums[cont])
	{
		if (cont != 0 && (nums[cont] == 43 || nums[cont] == 45))
		{
			return (0);
		}
		cont ++;
	}
	if (cont == (int)ft_strlen(nums))
		return (1);
	return (0);
}
