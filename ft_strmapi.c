/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:01:45 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/06 18:17:53 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned	int, char))
{
	char	*str;
	size_t	index;
	size_t	s_len;

	if (!s)
		return ((void *)0);
	index = 0;
	s_len = ft_strlen(s);
	str = malloc(sizeof(char *) * s_len + 1);
	if (!str)
		return ((void *)0);
	while (s[index++])
		str[index] = (*f)(index, s[index]);
	str[index++] = '\0';
	return (str);
}

// int main()
// {
// 	char	s[] = "hello world";
// }
