/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:46:42 by arthur            #+#    #+#             */
/*   Updated: 2024/11/28 15:05:07 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	while (s[length])
	{
		length++;
	}
	return (write(1, s, length));
}
