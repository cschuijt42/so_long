/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_pass_helpers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 22:09:28 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/21 22:09:28 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_o(char c);

unsigned char	determine_wall_sprite(t_map *map, size_t i)
{
	unsigned char	surroundings;
	size_t			size;
	size_t			width;

	surroundings = 0;
	size = map->size;
	width = map->width;
	if (i >= width + 1 && is_o(map->render_categories[i - width - 1]))
		surroundings += 128;
	if (i >= width && is_o(map->render_categories[i - width]))
		surroundings += 64;
	if (i >= width - 1 && is_o(map->render_categories[i - width + 1]))
		surroundings += 32;
	if (i < size - 1 && is_o(map->render_categories[i + 1]))
		surroundings += 16;
	if (i <= size - width - 1 && is_o(map->render_categories[i + width + 1]))
		surroundings += 8;
	if (i <= size - width && is_o(map->render_categories[i + width]))
		surroundings += 4;
	if (i <= size - width + 1 && is_o(map->render_categories[i + width - 1]))
		surroundings += 2;
	if (i >= 1 && is_o(map->render_categories[i - 1]))
		surroundings += 1;
	return (get_wall_sprite_from_surroundings(surroundings));
}

unsigned char	get_wall_sprite_from_surroundings(unsigned char s)
{
	return (0);
}

static int	is_o(char c)
{
	return (c == 'N' || c == 'F' || c == 'L' || c == 'P');
}
