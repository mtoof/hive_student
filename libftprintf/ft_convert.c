/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:36:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/08 21:23:14 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert(unsigned int num, int base, char sign)
{
	int	count;

	count = 0;
	if (num > 15)
	{
		count += ft_convert((num / base), base, sign);
		num = num % base;
	}
	if (num < 10)
	{
		ft_putchar((num % base) + '0');
		count++;
	}
	if (num >= 10 && num <= 15)
	{
		ft_putchar((num % base) + sign);
		count++;
	}
	return (count);
}
