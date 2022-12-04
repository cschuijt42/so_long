/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameplay.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 20:28:11 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/03 20:28:11 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(void *map_ptr)
{
	t_map	*map;

	map = (t_map *) map_ptr;
	if (map->lock_input)
		return ;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		try_move_player_up(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		try_move_player_left(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		try_move_player_down(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		try_move_player_right(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
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
