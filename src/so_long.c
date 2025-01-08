/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:57:41 by arthur            #+#    #+#             */
/*   Updated: 2024/12/02 15:50:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int close_win(t_data data)
{
	free(data.win.mlx);
	
	exit(1);
}

int	move(int keycode, t_data data)
{

	if (keycode == 2)
		move_right(&data);
	else if (keycode == 0)
		move_left(&data);
	else if (keycode == 1)
		move_down(&data);
	else if (keycode == 13)
		move_up(&data);
	else if (keycode == 53)
		exit(1);
	mlx_clear_window(data.win.mlx, data.win.mlx_win);
	find_player(&data);
	render_map(&data);
	render_player(&data);
	return (0);
}

int	key_hooks(t_data data)
{
	mlx_hook(data.win.mlx_win, 2, 1L << 0, move, &data);
	mlx_hook(data.win.mlx_win, 17, 1L << 17, close_win, &data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long <map_file>\n"), 1);
	data.map = get_map(argv[1]);
	if (data.map.x <= 0 || data.map.y <= 0)
		return (ft_printf("Invalid map dimensions\n"), 1);
	data.win.height = data.map.y * 32;
	data.win.width = data.map.x * 32;
	data.win.mlx = mlx_init();
	if (!data.win.mlx)
		return (ft_printf("Failed to initialize MLX\n"), 1);
	data.win.mlx_win = mlx_new_window(data.win.mlx, data.win.width, 
			data.win.height, "so_long");
	if (!data.win.mlx_win)
		return (ft_printf("Failed to create window\n"), 1);
	init_textures(&data);
	find_player(&data);
	render_map(&data);
	render_player(&data);
	mlx_loop_hook(data.win.mlx, key_hooks, &data);
	mlx_loop(data.win.mlx);
}
