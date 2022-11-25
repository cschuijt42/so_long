/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:15:34 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/15 15:15:34 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	render_map(t_map *map)
{
	size_t		i;

	i = 0;
	while (map->sprite_categories[i])
	{
		if (map->sprite_categories[i] == 'W')
			render_background_sprite(map, i, map->wall_sprites);
		if (map->sprite_categories[i] == 'N')
			render_background_sprite(map, i, map->wall_sprites);
		if (map->sprite_categories[i] == 'L')
			render_background_sprite(map, i, map->lava_sprites);
		if (map->sprite_categories[i] == 'F')
			render_background_sprite(map, i, map->wall_sprites);
		i++;
	}	
}

void	render_background_sprite(t_map *map, size_t i, uint8_t **sprites)
{
	t_sprite	*sprite;
	size_t		x_pos;
	size_t		y_pos;

	sprite = find_or_create_sprite(map, sprites, i);
	x_pos = render_x_pos(map, i);
	y_pos = render_y_pos(map, i);
	mlx_image_to_window(map->mlx, sprite->image, x_pos, y_pos);
}
