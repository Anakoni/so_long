/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:09:01 by arthur            #+#    #+#             */
/*   Updated: 2024/12/02 15:39:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_data *data)
{
	data->tex.bg = mlx_xpm_file_to_image(data->win.mlx, BG,
			&data->win.width, &data->win.height);
	data->tex.pl = mlx_xpm_file_to_image(data->win.mlx, PLAYER,
			&data->win.width, &data->win.height);
	data->tex.ob = mlx_xpm_file_to_image(data->win.mlx, ASTEROID,
			&data->win.width, &data->win.height);
	data->tex.col = mlx_xpm_file_to_image(data->win.mlx, STAR,
			&data->win.width, &data->win.height);
	data->tex.ptl = mlx_xpm_file_to_image(data->win.mlx, PORTAL,
			&data->win.width, &data->win.height);
	data->player.mcount = 0;
}

void	place_texture(t_window win, void *tex, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.mlx_win, tex, x * 32, y * 32);
}

void	render_map(t_data *data)
{
	int			x;
	int			y;

	y = 0;
	data->map.stars = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x && (data->map.map[y][x] != '\0'))
		{
			place_texture(data->win, data->tex.bg, x, y);
			if (data->map.map[y][x] == '1')
				place_texture(data->win, data->tex.ob, x, y);
			if (data->map.map[y][x] == 'E')
				place_texture(data->win, data->tex.ptl, x, y);
			if (data->map.map[y][x] == 'C')
			{
				place_texture(data->win, data->tex.col, x, y);
				data->map.stars += 1;
			}
			x++;
		}
		y++;
	}
	find_portal(data);
}

void	render_player(t_data *data)
{
	place_texture(data->win, data->tex.pl,
		data->player.actx, data->player.acty);
}
