/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:02:30 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/09 14:26:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		index;
	char		*new_str;

	if (!s1 || !s2)
		return ((void *)0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc((s1_len + s2_len) + 1);
	if (!new_str)
		return ((void *)0);
	index = 0;
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}

// while (*s1)
// 	new_str[index++] = *s1++;
// while (*s2)
// 	new_str[index++] = *s2++;
// new_str[index++] = '\0';
// int	main()
// {
//   char  s1[] = "hello world";
//   char  s2[] = " here I am";

//   printf("%s", ft_strjoin(s1, s2));
//   return 0;
// }