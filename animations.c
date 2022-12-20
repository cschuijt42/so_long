/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 00:00:31 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/04 00:00:31 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_sprites_for_animation(t_map *map)
{
	t_sprite	*sprite;

	sprite = map->sprites;
	while (sprite)
	{
		if (sprite->spritesheet == map->wall_sprites)
		{
			if (sprite->index == 90)
				sprite->animation_frames = 4;
			else
				sprite->animation_frames = 0;
		}
		else if (sprite->spritesheet == map->lava_sprites)
		{
			if (sprite->index > 1)
				sprite->animation_frames = 4;
			else
				sprite->animation_frames = 0;
		}
		sprite = sprite->next;
	}
}

void	animate_background_hook(void *map_ptr)
{
	static size_t	clock = 0;
	static size_t	offset = 0;
	t_sprite		*sprite;

	if (clock >= 4)
	{
		clock = 0;
		offset++;
		sprite = ((t_map *)map_ptr)->sprites;
		while (sprite)
		{
			if (sprite->animation_frames)
			{
				sprite->image->pixels = sprite->spritesheet[sprite->index + \
				(offset % sprite->animation_frames)];
			}
			sprite = sprite->next;
		}
	}
	else
		clock++;
}

void	animate_player_hook(void *map_ptr)
{
	static int		clock = 0;
	static int		offset = 0;
	t_map			*map;

	map = (t_map *) map_ptr;
	if (map->movement_clock < 8)
	{
		movement_animation_wrapper(map);
		clock = 6;
		offset = 2;
	}
	else
	{
		clock = (clock + 1) % 8;
		if (clock == 0)
		{
			offset = (offset + 1) % 4;
			map->player->image->pixels = \
			map->player_sprites[offset + map->player->facing_offset];
		}
	}
}
