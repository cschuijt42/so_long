/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_pass.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 21:31:49 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/26 21:31:49 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_in_floors(t_map *map)
{
	size_t		i;
	uint8_t		surroundings;
	t_floortile	*tile;

	i = 0;
	tile = initialize_tile_list();
	while (map->sprite_categories[i])
	{
		if (map->sprite_categories[i] == 'F' && map->render_terrain[i] == 0)
		{
			surroundings = determine_floor_surroundings(map, i);
			while (!floor_tile_fits_space(surroundings, tile->pattern))
				tile = tile->next;
			fill_in_floor_tile(map, i, tile->pattern);
			tile = tile->next;
		}
		i++;
	}
	free_tile_list(&tile);
}

uint8_t	determine_floor_surroundings(t_map *map, size_t i)
{
	uint8_t	surroundings;

	surroundings = 0;
	if (map->sprite_categories[i + 1] == 'F')
		surroundings |= 1 << 3;
	if (map->sprite_categories[i + map->width + 1] == 'F')
		surroundings |= 1 << 4;
	if (map->sprite_categories[i + map->width] == 'F')
		surroundings |= 1 << 5;
	if (map->sprite_categories[i + map->width - 1] == 'F')
		surroundings |= 1 << 6;
	return (surroundings);
}

int	floor_tile_fits_space(uint8_t surroundings, char *tile)
{
	unsigned int	i;

	i = 1;
	while (i < 5)
	{
		if (tile[i] && !(surroundings >> (i + 2) & 1))
			return (0);
		i++;
	}
	return (1);
}

void	fill_in_floor_tile(t_map *map, size_t i, char *tile)
{
	map->render_terrain[i] = tile[0];
	if (tile[1])
		map->render_terrain[i + 1] = tile[1];
	if (tile[2])
		map->render_terrain[i + map->width + 1] = tile[2];
	if (tile[3])
		map->render_terrain[i + map->width] = tile[3];
	if (tile[4])
		map->render_terrain[i + map->width - 1] = tile[4];
}
