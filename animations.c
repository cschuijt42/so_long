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

	if (clock >= 8)
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
	clock++;
	if (clock >= 12)
	{
		clock = 0;
		offset++;
		if (offset > 3)
			offset = 0;
		map->player->image->pixels = map->player_sprites[offset + 4];
	}
}
