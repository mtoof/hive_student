/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:37:30 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:13:06 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		++s1;
		++s2;
	}
	return (0);
}

// int main(void)
// {
// 	char	str[] = "Hello world";
// 	char	str2[] = "Hell";

// 	printf("%d\n",ft_memcmp(str, str2, 15));
// 	printf("%d\n",memcmp(str, str2, 15));

// 	return (0);
// }