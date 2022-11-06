/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:38:13 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:13:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return ((void *)0);
}

// int	main(void)
// {
// 	char	str1[] = "hello \0 world";

// 	printf("%s\n", ft_memchr(str1, '\0', 10));
// 	printf("%s", memchr(str1, '\0', 10));
// 	return (0);
// }
