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
	if (patrol->move_direction == 0)
	{
		if (map->content[patrol->pos - map->width] == '1')
			patrol->move_direction = 2;
	}
	else if (patrol->move_direction == 1)
	{
		if (map->content[patrol->pos + 1] == '1')
			patrol->move_direction = 3;
	}
	else if (patrol->move_direction == 2)
	{
		if (map->content[patrol->pos + map->width] == '1')
			patrol->move_direction = 0;
	}
	else if (patrol->move_direction == 3)
	{
		if (map->content[patrol->pos - 1] == '1')
			patrol->move_direction = 1;
	}
	update_patrol_facing_offset(patrol);
}

void	update_patrol_facing_offset(t_patrol *patrol)
{
	if (patrol->move_direction == 3)
	{
		patrol->facing_offset = 4;
	}
	else
	{
		patrol->facing_offset = 0;
	}
}
