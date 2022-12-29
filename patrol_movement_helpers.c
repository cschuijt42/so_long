/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol_movement_helpers.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 18:04:44 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/28 18:04:44 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_patrol_movement_direction(t_map *map, t_patrol *patrol)
{
	if (patrol->move_direction == dir_up)
	{
		if (map->content[patrol->pos - map->width] == '1')
			patrol->move_direction = dir_down;
	}
	else if (patrol->move_direction == dir_right)
	{
		if (map->content[patrol->pos + 1] == '1')
			patrol->move_direction = dir_left;
	}
	else if (patrol->move_direction == dir_down)
	{
		if (map->content[patrol->pos + map->width] == '1')
			patrol->move_direction = dir_up;
	}
	else if (patrol->move_direction == dir_left)
	{
		if (map->content[patrol->pos - 1] == '1')
			patrol->move_direction = dir_right;
	}
	update_patrol_facing_offset(patrol);
}

void	update_patrol_facing_offset(t_patrol *patrol)
{
	if (patrol->move_direction == dir_down || \
		patrol->move_direction == dir_left)
	{
		patrol->facing_offset = 4;
	}
	else
	{
		patrol->facing_offset = 0;
	}
}

size_t	patrol_indicator_pos(t_map *map, t_patrol *patrol)
{
	if (patrol->move_direction == dir_up)
	{
		return (patrol->pos - map->width);
	}
	else if (patrol->move_direction == dir_right)
	{
		return (patrol->pos + 1);
	}
	else if (patrol->move_direction == dir_down)
	{
		return (patrol->pos + map->width);
	}
	else if (patrol->move_direction == dir_left)
	{
		return (patrol->pos - 1);
	}
	return (0);
}

void	update_patrol_movement_indicator(t_map *map, t_patrol *patrol)
{
	t_sprite		*sprite;

	sprite = find_or_create_sprite(map, map->bg_sprites, 13);
	sprite->image->instances[patrol->indicator_instance].x = \
		render_x_pos(map, patrol_indicator_pos(map, patrol));
	sprite->image->instances[patrol->indicator_instance].y = \
		render_y_pos(map, patrol_indicator_pos(map, patrol));
}
