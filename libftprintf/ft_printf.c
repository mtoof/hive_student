/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:42:22 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/08 21:24:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_check(va_list args, const char *tmp)
{
	char			*s;
	unsigned int	i;
	int				counter;

	counter = 0;
	i = 0;
	if (*tmp == 'c')
	{
		ft_putchar(va_arg(args, int));
		counter++;
	}
	else if (*tmp == 's')
		ft_putstr(va_arg(args, char *));
	else if (*tmp == 'X' || *tmp == 'x' || *tmp == 'd' || *tmp == 'i')
	{
		i = (va_arg(args, unsigned int));
		if (*tmp == 'X')
			counter += ft_convert(i, 16, 55);
		else if (*tmp == 'x')
			counter += ft_convert(i, 16, 87);
		else if (*tmp == 'd' || *tmp == 'i')
			ft_putnbr(i);
	}
	else if (*tmp == '%')
		ft_putchar('%');
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

int main(void)
{
	int ptr;

	ptr = 0;
	ptr = ft_printf("printf x: %x\n", -1);
	printf("%d\n", ptr);
	ptr = printf("printf x: %x\n", -1);
	printf("%d\n", ptr);
	return (0);
}
