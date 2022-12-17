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

static int    nlen(unsigned long n, int base)
{
    int    i;

    i = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        n = (n / base);
        i++;
    }
    return (i);
}

int    ft_convert(unsigned long num, int base, char sign)
{
    int    counter;
    int digit_counter;
    char nums[16] = "0123456789ABCDEF";
    char tmp;
    char *ptr;

    digit_counter = 0;
    counter = 0;
    digit_counter = nlen(num, base);
    ptr = (char *)malloc(sizeof(char)* digit_counter + 1);
    ptr[digit_counter--] = '\0';
    while (num != 0)
    {
      tmp = nums[num % base];
      if (tmp > '9')
        ptr[digit_counter--] = (tmp + sign);
      else
        ptr[digit_counter--] = tmp;
      num /= base;
    }
    counter += ft_putstr(ptr);
    return (counter);
}
