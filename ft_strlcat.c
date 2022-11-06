/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:28:07 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:12:36 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		dst_index;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	dst_index = dst_len;
	if (!src || !*src)
		return (dst_len);
	else if (dstsize < dst_len)
		return (dstsize + src_len);
	while (*src && dstsize > dst_len && dst_index != dstsize - 1)
		*(dst + dst_index++) = *src++;
	*(dst + dst_index) = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	src[20] = "hello world";
// 	char	dst[7] = "new new";

// 	printf("%zu\n",ft_strlcat(dst, src,4));
// 	printf("%s\n",dst);
// 	return (0);
// }
