/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   category_pass_updaters.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 15:08:51 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/20 15:08:51 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	north_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size - (map->width * 2))
	{
		if (map->sprite_categories[i] == 'W')
			if (map->sprite_categories[i + map->width] == ' ')
				map->sprite_categories[i] = 'N';
		i++;
	}
}

void	fill_floors_and_strip_walls(t_map *map)
{
	size_t	i;

	i = map->width;
	while (i < map->size - map->width)
	{
		if (map->sprite_categories[i] == ' ')
		{
			if (map->content[i] == 'E')
				map->sprite_categories[i] = 'E';
			else
				map->sprite_categories[i] = 'F';
		}
		i++;
	}
	i = 0;
	while (i < map->size)
	{
		if (!is_edge_wall(i, map))
			map->sprite_categories[i] = ' ';
		i++;
	}
}

int	is_edge_wall(size_t i, t_map *map)
{
	if (floor_or_north_wall(i - map->width - 1, map))
		return (1);
	if (floor_or_north_wall(i - map->width, map))
		return (1);
	if (floor_or_north_wall(i - map->width + 1, map))
		return (1);
	if (floor_or_north_wall(i - 1, map))
		return (1);
	if (floor_or_north_wall(i + 1, map))
		return (1);
	if (floor_or_north_wall(i + map->width - 1, map))
		return (1);
	if (floor_or_north_wall(i + map->width, map))
		return (1);
	if (floor_or_north_wall(i + map->width + 1, map))
		return (1);
	return (0);
}

int	floor_or_north_wall(size_t i, t_map *map)
{
	if (map->sprite_categories[i] == 'N' || map->sprite_categories[i] == 'F')
		return (1);
	if (map->sprite_categories[i] == 'E')
		return (1);
	return (0);
}
