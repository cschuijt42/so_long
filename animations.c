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
		if (sprite->spritesheet == map->bg_sprites)
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
	size_t			current_clock;
	static size_t	offset = 0;
	t_sprite		*sprite;

	current_clock = mlx_get_time() / BG_ANIMATION_INTERVAL;
	if (current_clock > clock)
	{
		clock = current_clock;
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
}

void	animate_characters_hook(void *map_ptr)
{
	static size_t	clock = 0;
	size_t			current_clock;				
	static int		offset = 0;
	t_map			*map;

	map = (t_map *) map_ptr;
	if (map->movement_clock < 8)
	{
		movement_animation_wrapper(map);
		offset = 0;
	}
	else
	{
		current_clock = mlx_get_time() / IDLE_ANIMATION_INTERVAL;
		if (current_clock > clock)
		{
			clock = current_clock;
			offset = (offset + 1) % 4;
			animate_player(map, offset);
			idle_animate_patrols(map, offset);
		}
	}
}

void	animate_player(t_map *map, size_t offset)
{
	static int	animation_part_two = 0;

	if (map->game_state == state_playing || map->game_state == state_victory)
	{
		map->player->image->pixels = \
			map->player_sprites[offset + map->player->facing_offset];
	}
	else if (map->game_state == state_loss_animation)
	{
		if (!animation_part_two)
		{
			map->player->image->pixels = \
				map->player_sprites[40 + offset + map->player->facing_offset];
			if (offset == 3)
				animation_part_two = 1;
		}
		else
		{
			map->player->image->pixels = \
				map->player_sprites[48 + offset + map->player->facing_offset];
			if (offset == 3)
				map->game_state = state_game_over;
		}
	}
}

void	idle_animate_patrols(t_map *map, size_t offset)
{
	t_patrol	*patrol;

	patrol = map->patrols;
	while (patrol)
	{
		patrol->image->pixels = \
		map->patrol_sprites[offset + patrol->facing_offset];
		patrol = patrol->next;
	}
}
