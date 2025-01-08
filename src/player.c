/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:55:13 by arthur            #+#    #+#             */
/*   Updated: 2024/12/28 16:55:30 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_data *data)
{
	if (data->map.map[data->player.acty][data->player.actx + 1] != '1' &&
		!(data->map.map[data->player.acty][data->player.actx + 1] == 'E' &&
			data->map.stars != 0))
	{
		data->map.map[data->player.acty][data->player.actx] = '0';
		data->player.actx += 1;
		data->player.mcount += 1;
		data->map.map[data->player.acty][data->player.actx] = 'P';
		ft_printf("Movement count : %d\n", data->player.mcount);
	}
}

void	move_left(t_data *data)
{
	if (data->map.map[data->player.acty][data->player.actx - 1] != '1' &&
		!(data->map.map[data->player.acty][data->player.actx - 1] == 'E' &&
			data->map.stars != 0))
	{
		data->map.map[data->player.acty][data->player.actx] = '0';
		data->player.actx -= 1;
		data->player.mcount += 1;
		data->map.map[data->player.acty][data->player.actx] = 'P';
		ft_printf("Movement count : %d\n", data->player.mcount);
	}
}

void	move_up(t_data *data)
{
	if (data->map.map[data->player.acty - 1][data->player.actx] != '1' &&
		!(data->map.map[data->player.acty - 1][data->player.actx] == 'E' &&
			data->map.stars != 0))
	{
		data->map.map[data->player.acty][data->player.actx] = '0';
		data->player.acty -= 1;
		data->player.mcount += 1;
		data->map.map[data->player.acty][data->player.actx] = 'P';
		ft_printf("Movement count : %d\n", data->player.mcount);
	}
}

void	move_down(t_data *data)
{
	if (data->map.map[data->player.acty + 1][data->player.actx] != '1' &&
		!(data->map.map[data->player.acty + 1][data->player.actx] == 'E' &&
			data->map.stars != 0))
	{
		data->map.map[data->player.acty][data->player.actx] = '0';
		data->player.acty += 1;
		data->player.mcount += 1;
		data->map.map[data->player.acty][data->player.actx] = 'P';
		ft_printf("Movement count : %d\n", data->player.mcount);
	}
}

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x && (data->map.map[y][x] != '\0'))
		{
			if (data->map.map[y][x] == 'P')
			{
				data->player.actx = x;
				data->player.acty = y;
				if (data->player.actx == data->map.portalx && data->player.acty == data->map.portaly)
				{
					exit(1);
				}
				return ;
			}
			x++;
		}
		y++;
	}
	data->player.actx = -1;
	data->player.acty = -1;
}
