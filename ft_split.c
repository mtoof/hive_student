/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:34:00 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/06 23:01:28 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count(char const *s, char c)
{
	
}
char	**ft_split(char const *s, char c)
{
	// size_t	s_len;
	int		index;
	int		str_indx;
	char	*str;
	char	**str2;
	
	if (!s)
		return ((void *)0);
	index = 0;
	while (s[index] != c)
		index++;
	str = malloc(sizeof(char) * (index + 1));
	if (!str)
		return ((void *)0);
	str_indx = 0;
	while(str_indx < index)
	{
		str[str_indx] = s[str_indx];
		str_indx++;
	}
	str[str_indx++] = '\0';
	str2 = &str;
	return (str2);
}

// int main(void)
// {
// 	char	str[] = "Hello world";

// 	printf("%p\n", ft_split(str,'o'));
// 	return (0);
// }