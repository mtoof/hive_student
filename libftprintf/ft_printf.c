/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:42:22 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/06 14:42:22 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	ft_check(va_list *args, const char *tmp)
{
	char			*s;
	unsigned int	i;
	if (*tmp == 'c')
	{
		i = va_arg(*args, int);
		ft_putchar(i);
	}
	else if (*tmp == 's')
	{
		s = va_arg(*args, char *);
		ft_putstr(s);
	}
	else if (*tmp == 'p')
	{
		i = va_arg(*args, int);
		ft_putnbr(i);
	}
	else if (*tmp == '%')
		ft_putchar('%');
}

int	ft_printf(const char *tmp, ...)
{
	int		state;
	int		counter;
	va_list	*args;

	state = 0;
	args = malloc(sizeof(va_list));
	va_start(*args, tmp);
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
	va_end(*args);
	return (0);
}

int main(void)
{
	char	*ptr;

	ft_printf("%s\n%c %c %c %p\n%%%%%%\n","Hello",'g','h','f',&ptr);
	printf("%i\n%%%%%%\n", 35441.65464);
	return (0);
}