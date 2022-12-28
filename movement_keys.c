/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_keys.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 20:28:11 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/03 20:28:11 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement_wrapper(t_map *map, char key)
{
	if (key == 'W')
		try_move_player_up(map);
	else if (key == 'A')
		try_move_player_left(map);
	else if (key == 'S')
		try_move_player_down(map);
	else if (key == 'D')
		try_move_player_right(map);
}

void	try_move_player_up(t_map *map)
{
	if (map->content[map->player->pos - map->width] == '1')
		return ;
	map->player->move_direction = dir_up;
	map->movement_clock = 0;
	map->lock_input = 1;
	animate_player_movement_up(map);
}

void	try_move_player_right(t_map *map)
{
	if (map->content[map->player->pos + 1] == '1')
		return ;
	map->player->move_direction = dir_right;
	map->player->facing_offset = 0;
	map->movement_clock = 0;
	map->lock_input = 1;
	animate_player_movement_right(map);
}

void	try_move_player_down(t_map *map)
{
	if (map->content[map->player->pos + map->width] == '1')
		return ;
	map->player->move_direction = dir_down;
	map->movement_clock = 0;
	map->lock_input = 1;
	animate_player_movement_down(map);
}

void	try_move_player_left(t_map *map)
{
	if (map->content[map->player->pos - 1] == '1')
		return ;
	map->player->move_direction = dir_left;
	map->player->facing_offset = 4;
	map->movement_clock = 0;
	map->lock_input = 1;
	animate_player_movement_left(map);
}
