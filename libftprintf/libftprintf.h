/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:15 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/08 20:39:19 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
int		ft_printf(const char *tmp, ...);
int		ft_convert(unsigned int num, int base, char sign);

#endif