/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:17 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:13:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;
	int		i;

	if (!dst && !src)
		return ((void *)0);
	i = 0;
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (i < (int)n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	*str1 = NULL;
// 	char	*str2 = NULL;

// 	// printf("%s\n", memcpy(str1 + 2, str1, 5));
// 	// printf("%s\n", str1);
// 	printf("%s\n", ft_memcpy(str2, str1, 5));
// 	printf("%s\n", memcpy(str2, str1, 0));
// 	// printf("%s\n", str1);
// 	return (0);
// }
