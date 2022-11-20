/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering_passes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 13:32:04 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/17 13:32:04 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	categorize_map_walls(t_map *map)
{
	char	*c_map;
	size_t	y;
	size_t	map_size;

	y = 0;
	map_size = ft_strlen(map->content);
	c_map = ft_calloc(1, map_size + 1);
	ft_memset(c_map, ' ', map_size);
	ft_memset(c_map, 'W', map->width);
	ft_memset(&c_map[(map->width * map->height) - map->width], 'W', map->width);
	while (y < map->height)
	{
		c_map[y * map->width] = 'W';
		c_map[((y + 1) * map->width) - 1] = 'W';
		y++;
	}
	map->render_categories = c_map;
	initial_wall_seed(map);
	recursive_walls(map);
	lava_and_pillars(map);
}
