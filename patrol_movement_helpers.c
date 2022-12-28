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
	if (patrol->move_direction == dir_up || patrol->move_direction == dir_right)
	{
		patrol->facing_offset = 4;
	}
	else
	{
		patrol->facing_offset = 0;
	}
}
