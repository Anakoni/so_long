/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:52:02 by arthur            #+#    #+#             */
/*   Updated: 2024/11/28 15:04:46 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-", 1);
		count += write(1, "2", 1);
		count += write(1, "147483648", 9);
	}
	else
	{
		if (nb < 0)
		{
			count += ft_printchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			count += ft_printnbr(nb / 10);
		}
		count += ft_printchar(nb % 10 + '0');
	}
	return (count);
}

/* int main()
{
	ft_putchar_fd(48368, 1);
	return (0);
} */
