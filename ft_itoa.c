/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:59:27 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/08 12:10:34 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 2;
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		i += 1;
	}
	while (n >= 10)
	{
		n = (n / 10);
		i++;
	}
	if (n < 10 && n != 0)
		n = n % 10;
	i++;
	return (i);
}

static char	*handle(char *num_str, int n, int n_len)
{
	int	index;
	int	triger;

	index = n_len;
	triger = 0;
	if (n < 0)
		triger = 1;
	while (n_len-- > triger)
	{
		if (n < 0)
		{
			num_str[0] = '-';
			n = -n;
		}
		if (n < 10)
			num_str[n_len] = n + '0';
		if (n >= 10)
		{
			num_str[n_len] = (n % 10) + '0';
			n = n / 10;
		}
	}
	num_str[index++] = '\0';
	return (num_str);
}

static char	*handle_min(char *num_str, int n, int n_len)
{
	int	index;

	index = n_len;
	while (n_len-- > 2)
	{
		if (n < 0)
		{
			num_str[0] = '-';
			num_str[1] = '2';
			n = 147483648;
		}
		if (n < 10)
			num_str[n_len] = n + '0';
		if (n >= 10)
		{
			num_str[n_len] = (n % 10) + '0';
			n = n / 10;
		}
	}
	num_str[index++] = '\0';
	return (num_str);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		n_len;

	n_len = nlen(n);
	num_str = (char *)malloc(sizeof(char) * n_len + 1);
	if (!num_str)
		return ((void *)0);
	if (n == -2147483648)
		handle_min(num_str, n, n_len);
	else
		handle(num_str, n, n_len);
	return (num_str);
}
