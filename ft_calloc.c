/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:33:28 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/07 16:38:28 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_mem;
	size_t	size_alloc;

	size_alloc = size * count;
	alloc_mem = (void *)malloc(sizeof(char) * size_alloc);
	if (!alloc_mem)
		return ((void *)0);
	ft_bzero(alloc_mem, size_alloc);
	return (alloc_mem);
}
