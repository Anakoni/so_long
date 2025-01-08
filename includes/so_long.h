/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:14:52 by arthur            #+#    #+#             */
/*   Updated: 2024/12/02 15:54:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>

# ifndef BG
#  define BG "assets/space.xpm"
# endif

# ifndef PLAYER
#  define PLAYER "assets/ship.xpm"
# endif

# ifndef ASTEROID
#  define ASTEROID "assets/asteroid.xpm"
# endif

# ifndef PORTAL
#  define PORTAL "assets/portal.xpm"
# endif

# ifndef STAR
#  define STAR "assets/star.xpm"
# endif

typedef struct s_mlx_window
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
}	t_window;

typedef struct s_texture
{
	void	*ob;
	void	*bg;
	void	*pl;
	void	*col;
	void	*ptl;
}	t_texture;

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
	int		stars;
	int		portalx;
	int		portaly;
	int		player;
	int		portal;
	int		starcount;
}	t_map;

typedef struct s_player
{
	int		actx;
	int		acty;
	int		mcount;
}	t_player;

typedef struct s_data
{
	t_window	win;
	t_player	player;
	t_map		map;
	t_texture	tex;
}	t_data;

t_map		get_map(char *path);
void		render_map(t_data *data);
void		init_textures(t_data *data);
void		place_texture(t_window win, void *tex, int x, int y);
void 		move_right(t_data *data);
void 		move_left(t_data *data);
void 		move_up(t_data *data);
void 		move_down(t_data *data);
void		find_player(t_data *data);
void		render_player(t_data *data);
void		find_portal(t_data *data);
void		check_map(t_map *data);
void		free_all(int i, char **to_free);

#endif