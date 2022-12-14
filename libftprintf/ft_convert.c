/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:36:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/14 16:21:46 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned long num, int base, char sign)
{
	int	counter;

	counter = 0;
	if (num > 15)
	{
		counter += ft_convert((num / base), base, sign);
		num = num % base;
	}
	if (num < 10)
		counter += ft_putchar((num % base) + '0');
	if (num >= 10 && num <= 15)
		counter += ft_putchar((num % base) + sign);
	return (counter);
}
