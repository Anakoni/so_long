/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:14:52 by arthur            #+#    #+#             */
/*   Updated: 2024/11/20 00:55:51 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/libft.h"

typedef struct s_mlx_window
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
}	t_window;


#endif