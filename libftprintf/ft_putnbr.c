/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:55:28 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/14 13:44:20 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int nb, int base, int sign)
{
	int	counter;

	counter = 0;
	if (sign == 0)
	{
		if ((int)nb < 0)
		{
		counter += ft_putchar('-');
		nb = (int)nb * -1;
		}
	}
	if (nb < 10)
		counter += ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		counter += ft_putnbr(nb / base, base, sign);
		counter += ft_putchar(nb % base + '0');
	}
	return (counter);
}
