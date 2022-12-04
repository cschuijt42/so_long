/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   north_walls.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 23:05:25 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/04 23:05:25 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_in_north_wall_sprites(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size)
	{
		if (map->sprite_categories[i] == 'N')
			i += fill_in_north_wall_segment(map, i);
		else
			i++;
	}
}

size_t	fill_in_north_wall_segment(t_map *map, size_t i)
{
	size_t	len;
	size_t	iterator;

	len = 0;
	while (map->sprite_categories[i + len] == 'N')
		len++;
	if (len >= 5)
		decorate_north_wall_segment(map, i, len);
	iterator = 0;
	while (iterator < len)
	{
		if (!map->render_terrain[i + iterator])
			map->render_terrain[i + iterator] = undecorated_north_wall_sprite();
		iterator++;
	}
	return (len);
}

void	decorate_north_wall_segment(t_map *map, size_t i, size_t len)
{
	size_t	remainder;

	remainder = len % 3;
	if (remainder == 2)
	{
		map->render_terrain[i + (len / 3)] = 90;
		map->render_terrain[i + len - (len / 3) - 1] = 90;
	}
	else
	{
		map->render_terrain[i + (len / 3) - 1] = 90;
		map->render_terrain[i + len - (len / 3)] = 90;
	}	
}

uint8_t	undecorated_north_wall_sprite(void)
{
	static size_t	i = 0;

	i++;
	if (i % 20 == 4)
		return (61);
	if (i % 20 == 11)
		return (62);
	if (i % 20 == 15)
		return (63);
	return (60);
}
