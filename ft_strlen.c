/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:45:01 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/12 14:37:44 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	str[] = "hello world";

// 	printf("%zu", ft_strlen(str));
// 	printf("%zu", strlen(str));
// 	return (0);
// }