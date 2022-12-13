/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:42:22 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/13 13:47:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list args, const char *tmp)
{
	unsigned int	i;
	int				counter;

	counter = 0;
	i = 0;
	if (*tmp == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (*tmp == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (*tmp == 'X')
		counter += ft_convert(va_arg(args, unsigned int), 16, 55);
	else if (*tmp == 'x')
		counter += ft_convert(va_arg(args, unsigned int), 16, 87);
	else if (*tmp == 'd' || *tmp == 'i')
		counter += ft_putnbr(va_arg(args, int), 10, 1);
	else if (*tmp == 'u')
		counter += ft_putnbr(va_arg(args, int), 10, -1);
	else if (*tmp == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *tmp, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, tmp);
	while (*tmp)
	{
		if (*tmp != '%')
		{
			ft_putchar(*tmp);
			counter++;
		}
		else if (*tmp == '%')
		{
			tmp++;
			counter += ft_check(args, tmp);
		}
		tmp++;
	}
	va_end(args);
	return (counter);
}

// int main(void)
// {
// 	int ptr;

// 	ptr = 0;
// 	ptr = ft_printf("printf x: %d\n", -2147483648);
// 	return (0);
// }
