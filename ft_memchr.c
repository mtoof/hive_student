/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:38:13 by mtoof             #+#    #+#             */
/*   Updated: 2022/10/28 19:02:35 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (char *)s;
	while (n--)
	{
		if (!*str)
			return (0);
		else if (*str == (unsigned char)c)
			return (str);
		str++;
	}

}

// int	main(void)
// {
// 	char	str1[] = "hello world";

// 	printf("%s", ft_memchr(str1, 'w', 10));
// 	return (0);
// }
