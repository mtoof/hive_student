/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:08:44 by mtoof             #+#    #+#             */
/*   Updated: 2022/10/25 17:23:14 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
	{
		*ptr++ = c;
	}
	return (b);
}

// int	main(void)
// {
// 	int	str[] = {1,2,3,4,5,6,4};

// 	printf("%s",ft_memset(str, '1', 8*sizeof(char)));
// 	return (0);
// }
