/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:36:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/18 23:41:35 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nlen(unsigned long n, int base, char sign)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (sign == 1)
	{
		if ((int)n < 0)
		{
		n = (int)n * -1;
		i++;
		}
	}
	while (n)
	{
		n = (n / base);
		i++;
	}
	return (i);
}

int	ft_convert(unsigned long num, int base, char sign)
{
	int		counter;
	int		digit_counter;
	char	*nums;
	char	*ptr;

	nums = "0123456789ABCDEF";
	counter = 0;
	digit_counter = nlen(num, base, sign);
	ptr = (char *)malloc(sizeof(char) * digit_counter + 1);
	if (!ptr)
		return (0);
	ptr[digit_counter--] = '\0';
	if (num == 0)
		ptr[digit_counter--] = '0';
	while (num)
	{
		if (nums[num % base] > '9')
			ptr[digit_counter--] = (nums[num % base] + sign);
		else
			ptr[digit_counter--] = nums[num % base];
		num /= base;
	}
	counter += ft_putstr(ptr);
	free(ptr);
	return (counter);
}
