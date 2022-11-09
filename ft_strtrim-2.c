/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:59:28 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/08 15:37:55 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	b_trim(char const *s1, char const *set, size_t s1_len)
{
	int	set_index;
	int	s1_bindex;

	set_index = 0;
	s1_bindex = (int)s1_len - 1;
	while (set[set_index])
	{
		if (set[set_index] == s1[s1_bindex])
		{
			s1_bindex--;
			set_index = 0;
		}
		set_index++;
	}
	return (s1_bindex);
}

static int	f_trim(char const *s1, char const *set)
{
	int	s1_index;
	int	set_index;

	s1_index = 0;
	set_index = 0;
	while (set[set_index])
	{
		if (set[set_index] == s1[s1_index])
		{
			s1_index++;
			set_index = 0;
		}
		set_index++;
	}
	return (s1_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		s1_len;
	int		s1_start_i;
	int		s1_end_i;

	if (!s1)
		return ((void *)0);
	// if (!set && s1)
	// 	return (s1);
	s1_len = ft_strlen(s1);
	s1_start_i = f_trim(s1, set);
	s1_end_i = b_trim(s1, set, s1_len);
		new_str = malloc(s1_end_i - s1_start_i + 2);
	if (!new_str)
		return ((void *)0);
	ft_strlcpy(new_str, s1 + s1_start_i, (s1_end_i - s1_start_i) + 2);
	return (new_str);
	return (new_str);
}

// int	main(void)
// {
// 	char	str[] = "hello world";
// 	char	set[] = "dhelo";

// 	printf("%s\n", ft_strtrim(str, set));
// 	return (0);
// }
