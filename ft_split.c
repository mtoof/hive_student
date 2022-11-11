/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:15 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/11 19:57:52 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *str, char c)
{
	int		i;
	int		w_counter;

	w_counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w_counter++;
		i++;
	}
	return (w_counter);
}

static void	ft_free(char **str, int index)
{
	while (index--)
		free(str[index]);
	free(str);
}

static int	words_len(char const *s, char c, char **new_str)
{
	int		j;
	int		len;

	len = 0;
	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		new_str[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!new_str[j])
		{
			ft_free(new_str, j);
			return (0);
		}
		ft_strlcpy(new_str[j], s, len + 1);
		while (*s != c && *s != '\0')
			s++;
		len = 0;
		j++;
	}
	return (1);
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
	new_str = (char **)malloc(sizeof(*new_str) * (words_c + 1));
	if (!new_str)
		return (NULL);
	if (!words_len(s, c, new_str))
		return (NULL);
	else
		new_str[words_c] = NULL;
	return (new_str);
}

// int	main(void)
// {
// 	int		i;
// 	char	c = ' ';
// 	char	**matrix;

// 	i = 0;
// 	char	*str = NULL;
// 	matrix = ft_split(str, c);
// 	while (matrix[i])
// 	{
// 		printf("%s", matrix[i]);
// 		i++;
// 	}
// 	return (0);
// }
