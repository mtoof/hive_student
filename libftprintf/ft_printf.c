/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:42:22 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/07 16:06:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	convert(long num, int base)
{
	char	result[] = "0123456789ABCDEF";
	char	data[65];
	char	*ptr;

	ptr = &data[64];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = result[num % base];
		num /= base;
	}
	while (*ptr)
	{
		ft_putchar(*ptr);
		ptr++;
	}
}

static void	ft_check(va_list args, const char *tmp)
{
	char			*s;
	unsigned long	i;

	i = 0;
	if (*tmp == 'c')
	{
		i = va_arg(args, int);
		ft_putchar(i);
	}
	else if (*tmp == 's')
	{
		s = va_arg(args, char *);
		ft_putstr(s);
	}
	else if (*tmp == 'x')
	{
		i = (va_arg(args, long));
		convert(i, 16);
	}	
	else if (*tmp == '%')
		ft_putchar('%');
}

int	ft_printf(const char *tmp, ...)
{
	int		state;
	int		counter;
	va_list	args;

	state = 0;
	va_start(args, tmp);
	while (*tmp)
	{
		if (*tmp != '%')
			ft_putchar(*tmp);
		else if (*tmp == '%')
		{
			tmp++;
			ft_check(args, tmp);
		}
		tmp++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	char	*ptr;

	ft_printf("%x", 45);
	return (0);
}