/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:28:07 by mtoof             #+#    #+#             */
/*   Updated: 2022/10/28 16:37:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	dst_index;

	i = 0;
	if (dstsize == 0)
		return((dstsize) - strlen(dst) - 1);
	dst_index = ft_strlen(dst);
	while (i < ((int)dstsize - 2))
	{
		dst[dst_index] = src[i];
		dst_index++;
		i++;
	}
	dst[dst_index] = '\n';
	return (ft_strlen(dst));
}

// int main(void)
// {
// 	char	src[11] = "hello world";
// 	char	dst[16] = "win win";

// 	printf("%zu\n",strlcat(dst, src,0));
// 	printf("%s\n",dst);
// 	return (0);
// }