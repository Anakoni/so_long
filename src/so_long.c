/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:57:41 by arthur            #+#    #+#             */
/*   Updated: 2024/11/24 19:10:45 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long.h"

void render_line(char *line, int y, void *mlx, void *win, void *obstacle, void *background)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] == '1')
        {
            mlx_put_image_to_window(mlx, win, obstacle, (i * 32), (y * 32));
        }
        else
        {
            mlx_put_image_to_window(mlx, win, background, (i * 32), (y * 32));
        }
        i++;
    }
}

int	main(void)
{
	t_window	win;
	void		*img;
	char		*vars;
	char 		*line;	
	int			i;

	int couscous = open("maps/simple.ber", O_RDONLY);
	vars = get_next_line(couscous);
	win.width = ((ft_strlen(vars) - 1) * 32);
	i = 0;
	while (vars)
	{
		vars = get_next_line(couscous);
		i++;
	}
	close(couscous);
	win.height = i * 32;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, win.width, win.height, "so_long");
	void	*obstacle = mlx_xpm_file_to_image(win.mlx, "assets/obstacle.xpm", &win.width, &win.height);
	void	*background = mlx_xpm_file_to_image(win.mlx, "assets/space.xpm", &win.width, &win.height);
	int y = 0;
	couscous = open("maps/simple.ber", O_RDONLY);
    while ((line = get_next_line(couscous)) != NULL)
    {
        render_line(line, y, win.mlx, win.mlx_win, obstacle, background);
        free(line);
        y++;
    }

	close(couscous);
	mlx_loop(win.mlx);
}