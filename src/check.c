/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:11:25 by arthur            #+#    #+#             */
/*   Updated: 2024/12/02 15:54:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->player = 0;
	map->portal = 0;
	map->starcount = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x && (map->map[y][x] != '\0'))
		{
			if (map->map[y][x] == 'P')
				map->player += 1;
			if (map->map[y][x] == 'E')
				map->portal  += 1;
			if (map->map[y][x] == 'C')
				map->starcount += 1;
			x++;
		}
		y++;
	}
	if (map->player != 1 || map->portal != 1 || map->starcount < 1)
		exit(EXIT_FAILURE);
}