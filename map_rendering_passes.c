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

static void	recursive_walls(t_map *map);
static int	neighbors_wall(t_map *map, size_t i);
static int	can_be_wall(t_map *map, size_t i);

void	categorize_map_walls(t_map *map)
{
	char	*c_map;
	size_t	y;
	size_t	map_size;

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
	map->map_wall_categories = c_map;
	recursive_walls(map);
	// lava_and_pillars(map);
}

static void	recursive_walls(t_map *map)
{
	size_t	i;
	size_t	changed;
	size_t	map_size;

	map_size = ft_strlen(map->content);

	i = map->width;
	changed = 0;
	while (i < map_size - map->width)
	{
		if (map->content[i] == '1' && map->map_wall_categories[i] == ' ')
		{
			if (neighbors_wall(map, i) && can_be_wall(map, i))
			{
				map->map_wall_categories[i] = 'W';
				changed++;
			}
		}
		i++;
	}
	if (changed)
		recursive_walls(map);
}

static int	neighbors_wall(t_map *map, size_t i)
{
	if (map->map_wall_categories[i + 1] == 'W')
		return (1);
	if (map->map_wall_categories[i - 1] == 'W')
		return (1);
	if (map->map_wall_categories[i + map->width] == 'W')
		return (1);
	if (map->map_wall_categories[i - map->width] == 'W')
		return (1);
	return (0);
}

static int	can_be_wall(t_map *map, size_t i)
{
	if (map->content[i + map->width] == '1')
		return (1);
	if (map->content[i - map->width] == '1')
		return (1);
	return (0);
}
