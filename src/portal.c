/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:04:01 by arthur            #+#    #+#             */
/*   Updated: 2024/12/01 19:05:39 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_portal(t_data *data)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x && (data->map.map[y][x] != '\0'))
		{
			if (data->map.map[y][x] == 'E')
			{
				data->map.portalx = x;
				data->map.portaly = y;
				return ;
			}
			x++;
		}
		y++;
	}
	data->map.portalx = -1;
	data->map.portaly = -1;
}