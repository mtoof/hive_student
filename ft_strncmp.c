/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:04:47 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:12:22 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "hel\0hel";
// 	char	str2[] = "hel\0hel";

// 	printf("%d\n", ft_strncmp(str1, str2, 15));
// 	printf("%d", strncmp(str1, str2, 15));

// 	return (0);
// }
