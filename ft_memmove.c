/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:03:17 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:12:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	char		*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (src_ptr == dst_ptr)
		return (dst);
	if (src_ptr < dst_ptr)
	{
		src_ptr = src_ptr + len - 1;
		dst_ptr = dst_ptr + len - 1;
		while (len--)
			*dst_ptr-- = *src_ptr--;
	}
	else
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	src[10] = "newstring";

// 	printf("my memmove :   %s\n",ft_memmove(src + 2, src, 5));
// 	// printf("Real memmove : %s\n",memmove(src + 2, src, 5));
// 	// ft_memmove(dest, dest + 2, 2);

// 	return (0);
// }
