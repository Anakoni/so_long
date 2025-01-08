/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:52:02 by arthur            #+#    #+#             */
/*   Updated: 2024/11/28 15:05:11 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_printunbr(nb / 10);
	count += ft_printchar(nb % 10 + '0');
	return (count);
}

/* int main()
{
	ft_putchar_fd(48368, 1);
	return (0);
} */
