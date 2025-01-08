/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 04:42:23 by aperceva          #+#    #+#             */
/*   Updated: 2024/11/28 15:04:39 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversion(char arg, va_list ptr)
{
	if (arg == 'c')
		return (ft_printchar(va_arg(ptr, int)));
	else if (arg == 's')
		return (ft_printstr(va_arg(ptr, char *)));
	else if (arg == 'p')
		return (ft_printptr(va_arg(ptr, unsigned long long)));
	else if (arg == 'i' || arg == 'd')
		return (ft_printnbr(va_arg(ptr, int)));
	else if (arg == 'u')
		return (ft_printunbr(va_arg(ptr, unsigned int)));
	else if (arg == 'x' || arg == 'X')
		return (ft_printhex(va_arg(ptr, int), arg));
	else if (arg == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *tst, ...)
{
	va_list	ptr;
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	va_start(ptr, tst);
	while (tst[i])
	{
		if (tst[i] == '%')
		{
			sum += conversion(tst[i + 1], ptr);
			i += 2;
		}
		else
		{
			write(1, &tst[i], 1);
			sum++;
			i++;
		}
	}
	va_end(ptr);
	return (sum);
}
/* int main()
{
	ft_printf(" %d ", 10);
	return 0;
} */
