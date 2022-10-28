/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:40:29 by mtoof             #+#    #+#             */
/*   Updated: 2022/10/28 16:37:57 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index_s;
	int		index_str;
	char	*str;

	index_s = strlen(s);
	index_str = 0;
	while (s[index_s] != c)
		index_s--;
	while (s[index_s] != '\0')
	{
		str[index_str] = s[index_s];
		index_str++;
		index_s++;
	}
	str[index_str] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	str[] = "Hello world";

// 	printf("%s", ft_strrchr(str, 'l'));
// 	return (0);
// }