/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol_validation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 15:34:37 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/29 15:34:37 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	horizontal_space_to_move(t_map *map, size_t pos);
static size_t	vertical_space_to_move(t_map *map, size_t pos);

void	validate_patrol_locations(t_map *map)
{
	t_patrol	*patrol;
	size_t		move_room;

	patrol = map->patrols;
	while (patrol)
	{
		if (patrol->move_direction == dir_left || \
			patrol->move_direction == dir_right)
			move_room = horizontal_space_to_move(map, patrol->pos);
		else
			move_room = vertical_space_to_move(map, patrol->pos);
		if (move_room == 1)
			exit_message("patrol is stuck between two walls");
		patrol = patrol->next;
	}
	if (player_next_to_patrol(map))
		exit_message("player starts next to patrol");
}

static size_t	horizontal_space_to_move(t_map *map, size_t pos)
{
	size_t	space;
	size_t	i;

	space = 1;
	i = 0;
	while (map->content[pos - (i + 1)] != '1')
		i++;
	space += i;
	i = 0;
	while (map->content[pos + (i + 1)] != '1')
		i++;
	space += i;
	return (space);
}

static size_t	vertical_space_to_move(t_map *map, size_t pos)
{
	size_t	space;
	size_t	i;

	space = 1;
	i = 0;
	while (map->content[pos - (map->width * (i + 1))] != '1')
		i++;
	space += i;
	i = 0;
	while (map->content[pos + (map->width * (i + 1))] != '1')
		i++;
	space += i;
	return (space);
}
