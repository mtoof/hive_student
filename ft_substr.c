/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:47:23 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/04 19:08:36 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s || len == 0)
		return (0);
	str = malloc(len + 1);
	if (!str)
		return (0);
	if (start >= s_len)
	{
		str[0] = '\0';
		return (str);
	}
	while (i < len && s)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	str[20] = "hello world";

// 	printf("%s\n", ft_substr(str, 0, 12));
// 	return (0);
// }
