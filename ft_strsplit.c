/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:15 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/10 16:58:07 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *str, char c)
{
	int		i;
	int		c_counter;

	c_counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			c_counter++;
		i++;
	}
	return (c_counter);
}

static void	words_len(char const *s, char c, char **new_str)
{
	int		j;
	int		i;
	int		len;

	len = 0;
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (s[i] != c && *s)
		{
			len++;
			i++;
		}
		new_str[j++] = (char *)malloc(len + 1 * sizeof(char));
		if (!new_str[j])
		{
			while (j--)
				free(new_str[j]);
		}
		while(len--)
		{
			
		}
		len = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		words_c;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words_c = words_count(s, c);
	new_str = (char **)malloc(sizeof(*new_str) * words_c + 1);
	if (!new_str)
	{
		free(new_str);
		return (NULL);
	}
	words_len(s, c, new_str);
	return (new_str);
}

int	main(void)
{
	char	c = ' ';
	char	**ptr;
	char	str[] = "    hello    my friend";

	ptr = ft_split(str, c);
	printf("%s\n", ptr[1]);
	return (0);
}
