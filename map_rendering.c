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

	render_background_pixels(map);
	i = 0;
	while (map->sprite_categories[i])
	{
		if (map->sprite_categories[i] != ' ')
		{
			if (map->sprite_categories[i] == 'L')
				render_background_sprite(map, i, map->lava_sprites);
			else if (map->sprite_categories[i] == 'P')
				render_pillar(map, i);
			else
				render_background_sprite(map, i, map->bg_sprites);
		}
		i++;
	}
	render_collectibles(map);
	render_shadows(map);
	render_player(map);
	mark_sprites_for_animation(map);
}

void	render_background_pixels(t_map *map)
{
	size_t	screen;
	size_t	width;
	size_t	height;
	size_t	i;

	width = map->mlx->width;
	height = map->mlx->height;
	screen = width * height;
	map->background_fill = mlx_new_image(map->mlx, width, height);
	i = 0;
	while (i < screen)
	{
		mlx_put_pixel(map->background_fill, i % width, i / width, 0x353540FF);
		i++;
	}
	mlx_image_to_window(map->mlx, map->background_fill, 0, 0);
	mlx_set_instance_depth(map->background_fill->instances, 0);
}

void	render_background_sprite(t_map *map, size_t i, uint8_t **sprites)
{
	t_sprite	*sprite;
	size_t		sprite_index;
	size_t		xy[2];
	size_t		inst;

	sprite_index = (size_t)((unsigned char) map->render_terrain[i]);
	sprite = find_or_create_sprite(map, sprites, sprite_index);
	xy[0] = render_x_pos(map, i);
	xy[1] = render_y_pos(map, i);
	inst = mlx_image_to_window(map->mlx, sprite->image, xy[0], xy[1]);
	mlx_set_instance_depth(&sprite->image->instances[inst], 1);
}

void	render_shadow_sprite(t_map *map, size_t i)
{
	t_sprite	*sprite;
	size_t		sprite_index;
	size_t		xy[2];
	size_t		inst;

	sprite_index = (size_t)(unsigned char) map->render_shadows[i];
	sprite = find_or_create_sprite(map, map->shadow_sprites, sprite_index);
	xy[0] = render_x_pos(map, i);
	xy[1] = render_y_pos(map, i);
	inst = mlx_image_to_window(map->mlx, sprite->image, xy[0], xy[1]);
	mlx_set_instance_depth(&sprite->image->instances[inst], 2);
}

void	render_pillar(t_map *map, size_t i)
{
	t_sprite	*sprite;
	size_t		inst;
	size_t		x_pos;
	size_t		y_pos;

	render_background_sprite(map, i, map->bg_sprites);
	sprite = find_or_create_sprite(map, map->bg_sprites, 138);
	x_pos = render_x_pos(map, i);
	y_pos = render_y_pos(map, i - map->width);
	inst = mlx_image_to_window(map->mlx, sprite->image, x_pos, y_pos);
	mlx_set_instance_depth(&sprite->image->instances[inst], 5);
}
