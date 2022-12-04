/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 20:28:11 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/03 20:28:11 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_wrapper(t_map *map, char key)
{
	size_t	old_position;

	old_position = map->player->pos;
	if (key == 'W')
		try_move_player_up(map);
	if (key == 'A')
		try_move_player_left(map);
	if (key == 'S')
		try_move_player_down(map);
	if (key == 'D')
		try_move_player_right(map);
	if (map->player->pos != old_position)
	{
		if (map->content[map->player->pos] == 'C')
			try_pick_up_collectible(map, map->player->pos);
		if (map->content[map->player->pos] == 'E')
			try_exit_map(map);
	}
}

void	try_move_player_up(t_map *map)
{
	if (map->content[map->player->pos - map->width] == '1')
		return ;
	map->player->image->instances[0].y -= 32;
	map->player->pos -= map->width;
	map->player->moves_taken++;
	ft_printf("Moves: %d\n", map->player->moves_taken);
}

void	try_move_player_left(t_map *map)
{
	if (map->content[map->player->pos - 1] == '1')
		return ;
	map->player->image->instances[0].x -= 32;
	map->player->pos -= 1;
	map->player->moves_taken++;
	ft_printf("Moves: %d\n", map->player->moves_taken);
}

void	try_move_player_down(t_map *map)
{
	if (map->content[map->player->pos + map->width] == '1')
		return ;
	map->player->image->instances[0].y += 32;
	map->player->pos += map->width;
	map->player->moves_taken++;
	ft_printf("Moves: %d\n", map->player->moves_taken);
}

void	try_move_player_right(t_map *map)
{
	if (map->content[map->player->pos + 1] == '1')
		return ;
	map->player->image->instances[0].x += 32;
	map->player->pos += 1;
	map->player->moves_taken++;
	ft_printf("Moves: %d\n", map->player->moves_taken);
}
