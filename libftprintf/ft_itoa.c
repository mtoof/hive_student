/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:58:20 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/07 18:00:20 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	nlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n, int base)
{
	char	*num_str;
	int		n_len;
	long	number;

	number = n;
	n_len = nlen(n);
	num_str = (char *)malloc(sizeof(char) * n_len + 1);
	if (!num_str)
		return (NULL);
	num_str[n_len--] = '\0';
	if (number < 0)
	{
		num_str[0] = '-';
		number = -number;
	}
	while (number >= 10)
	{
		num_str[n_len--] = (number % base) + '0';
		number = number / base;
	}
	num_str[n_len] = number + '0';
	return (num_str);
}
