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

	y = 0;
	c_map = ft_calloc(map->size + 1, 1);
	if (!c_map)
		exit_perror("malloc error");
	ft_memset(c_map, ' ', map->size);
	ft_memset(c_map, 'W', map->width);
	ft_memset(&c_map[map->width * (map->height - 1)], 'W', map->width);
	while (y < map->height)
	{
		c_map[y * map->width] = 'W';
		c_map[((y + 1) * map->width) - 1] = 'W';
		y++;
	}
	map->sprite_categories = c_map;
	initial_wall_seed(map);
	recursive_walls(map);
	lava_and_pillars(map);
	north_walls(map);
	fill_floors_and_strip_walls(map);
}

void	fill_in_background_sprite_indexes(t_map *map)
{
	size_t	i;

	i = 0;
	map->render_terrain = ft_calloc(1, map->size + 1);
	if (!map->render_terrain)
		exit_perror("malloc error");
	while (map->sprite_categories[i])
	{
		if (map->sprite_categories[i] == 'W')
			map->render_terrain[i] = determine_wall_sprite(map, i);
		if (map->sprite_categories[i] == 'L')
			map->render_terrain[i] = determine_lava_sprite(map, i);
		if (map->sprite_categories[i] == 'P')
			map->render_terrain[i] = (unsigned char) 153;
		if (map->sprite_categories[i] == 'E')
			map->render_terrain[i] = determine_exit_sprite(map, i);
		i++;
	}
	fill_in_north_wall_sprites(map);
	fill_in_floors(map);
}
