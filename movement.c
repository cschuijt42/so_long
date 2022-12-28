/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 20:33:19 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/19 20:33:19 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_animation_wrapper(t_map *map)
{
	static size_t	clock = 0;

	clock = (clock + 1) % 3;
	if (clock == 0)
	{
		map->movement_clock++;
		if (map->movement_clock >= 8)
		{
			map->lock_input = 0;
			map->player->moves_taken++;
			run_gameplay_checks(map);
			render_gui(map);
			return ;
		}
		if (map->player->move_direction == 0)
			animate_player_movement_up(map);
		else if (map->player->move_direction == 1)
			animate_player_movement_right(map);
		else if (map->player->move_direction == 2)
			animate_player_movement_down(map);
		else if (map->player->move_direction == 3)
			animate_player_movement_left(map);
		patrol_movement_animation_wrapper(map);
	}
}

void	animate_player_movement_up(t_map *map)
{
	if (map->movement_clock < 4)
	{
		map->player->image->instances[0].y -= 8;
		map->player->image->pixels = map->player_sprites[16 + \
		map->player->facing_offset + map->movement_clock];
	}
	else
	{
		map->player->image->pixels = map->player_sprites[24 + \
		map->player->facing_offset + (map->movement_clock % 4)];
	}
	if (map->movement_clock == 5)
	{
		map->player->pos -= map->width;
	}
}

void	animate_player_movement_right(t_map *map)
{
	if (map->movement_clock < 4)
	{
		map->player->image->instances[0].x += 8;
		map->player->image->pixels = map->player_sprites[16 + \
		map->player->facing_offset + map->movement_clock];
	}
	else
	{
		map->player->image->pixels = map->player_sprites[24 + \
		map->player->facing_offset + (map->movement_clock % 4)];
	}
	if (map->movement_clock == 5)
	{
		map->player->pos += 1;
	}
}

void	animate_player_movement_down(t_map *map)
{
	if (map->movement_clock < 4)
	{
		map->player->image->instances[0].y += 8;
		map->player->image->pixels = map->player_sprites[16 + \
		map->player->facing_offset + map->movement_clock];
	}
	else
	{
		map->player->image->pixels = map->player_sprites[24 + \
		map->player->facing_offset + (map->movement_clock % 4)];
	}
	if (map->movement_clock == 5)
	{
		map->player->pos += map->width;
	}
}

void	animate_player_movement_left(t_map *map)
{
	if (map->movement_clock < 4)
	{
		map->player->image->instances[0].x -= 8;
		map->player->image->pixels = map->player_sprites[16 + \
		map->player->facing_offset + map->movement_clock];
	}
	else
	{
		map->player->image->pixels = map->player_sprites[24 + \
		map->player->facing_offset + (map->movement_clock % 4)];
	}
	if (map->movement_clock == 5)
	{
		map->player->pos -= 1;
	}
}
