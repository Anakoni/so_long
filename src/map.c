/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:54:13 by arthur            #+#    #+#             */
/*   Updated: 2024/12/02 15:39:53 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(int i, char **to_free)
{
	while (i < 0)
		free(to_free[i--]);
	free(to_free);
}

static t_map	map_size(char *path)
{
	int		fd;
	int		i;
	t_map	map;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map.x = ft_strlen(line) - 1;
	i = 1;
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	map.y = i - 1;
	free(line);
	close(fd);
	return (map);
}

t_map	get_map(char *path)
{
	int		fd;
	int		i;
	t_map	area;
	char	*line;

	area = map_size(path);
	line = NULL;
	area.map = malloc(sizeof(char *) * (area.y + 1));
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < area.y)
	{
		line = get_next_line(fd);
		area.map[i] = ft_strdup(line);
		i++;
	}
	close(fd);
	check_map(&area);
	return (free(line), area);
}
