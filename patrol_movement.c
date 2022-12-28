/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 16:41:47 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/28 16:41:47 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	patrol_movement_animation_wrapper(t_map *map)
{
	t_patrol	*patrol;

	patrol = map->patrols;
	while (patrol)
	{
		if (patrol->move_direction == 0)
			animate_patrol_movement_up(map, patrol);
		if (patrol->move_direction == 1)
			animate_patrol_movement_right(map, patrol);
		if (patrol->move_direction == 2)
			animate_patrol_movement_down(map, patrol);
		if (patrol->move_direction == 3)
			animate_patrol_movement_left(map, patrol);
		patrol = patrol->next;
	}
}

void	animate_patrol_movement_up(t_map *map, t_patrol *patrol)
{
	if (map->movement_clock == 5)
	{
		patrol->pos -= map->width;
		update_patrol_movement_direction(map, patrol);
	}
	if (map->movement_clock >= 5)
		return ;
	patrol->image->instances[0].y += 8;
	patrol->image->pixels = \
	map->patrol_sprites[7 + patrol->facing_offset + map->movement_clock];
}

void	animate_patrol_movement_right(t_map *map, t_patrol *patrol)
{
	if (map->movement_clock == 5)
	{
		patrol->pos += 1;
		update_patrol_movement_direction(map, patrol);
	}
	if (map->movement_clock >= 5)
		return ;
	patrol->image->instances[0].x += 8;
	patrol->image->pixels = \
	map->patrol_sprites[7 + patrol->facing_offset + map->movement_clock];
}

void	animate_patrol_movement_down(t_map *map, t_patrol *patrol)
{
	if (map->movement_clock == 5)
	{
		patrol->pos += map->width;
		update_patrol_movement_direction(map, patrol);
	}
	if (map->movement_clock >= 5)
		return ;
	patrol->image->instances[0].y -= 8;
	patrol->image->pixels = \
	map->patrol_sprites[7 + patrol->facing_offset + map->movement_clock];
}

void	animate_patrol_movement_left(t_map *map, t_patrol *patrol)
{
	if (map->movement_clock == 5)
	{
		patrol->pos -= 1;
		update_patrol_movement_direction(map, patrol);
	}
	if (map->movement_clock >= 5)
		return ;
	patrol->image->instances[0].x -= 8;
	patrol->image->pixels = \
	map->patrol_sprites[7 + patrol->facing_offset + map->movement_clock];
}
