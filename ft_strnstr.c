/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:00:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/10/30 00:00:11 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char	*little, size_t len)
{
	
	int		i, j;
	char	*str;

	str = (char *)big;
	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (len-- && *big && *little)
	{
		if (big[i] == little[j])
		{
			str += i;
			i++;
			j++;
		}
		i++;
	}

	return (str);
}

int main(void)
{
	char	str[] = "hello world";
	char	str2[] = "fd";

	printf("%s\n", ft_strnstr(str, str2, 10));
	printf("%s", strnstr(str, str2, 10));

	return (0);
}