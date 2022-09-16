
#include"libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && i < n)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j ++;
		}
		i ++;
	}
	return (0);
}