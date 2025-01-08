/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:33:44 by aperceva          #+#    #+#             */
/*   Updated: 2024/11/28 15:07:28 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ptrlen(uintptr_t ptr)
{
	size_t	total;

	total = 0;
	if (ptr <= 0)
		total++;
	while (ptr)
	{
		total++;
		ptr /= 16;
	}
	return (total);
}

static void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		count += ft_ptrlen(ptr);
		ft_putptr(ptr);
	}
	return (count);
}
