/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:40:29 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 15:12:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;
	char	*str;

	str = (char *)s;
	s_len = ft_strlen(s);
	while (s_len + 1 > 0)
	{
		if (s[s_len] == (char)c)
			return (str + s_len);
		if (!*s)
			return ((void *)0);
		s_len--;
	}
	return ((void *)0);
}

// int	main(void)
// {
// 	char	str[] = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ\0";

// 	printf("%s\n", ft_strrchr(str, '\0'));
// 	printf("%s", strrchr(str, '\0'));
// 	return (0);
// }