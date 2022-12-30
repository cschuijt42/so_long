/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 19:51:16 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/04 19:51:16 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(void *map_ptr)
{
	t_map	*map;

	map = (t_map *) map_ptr;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (map->game_state || map->lock_input)
		return ;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W) || \
		mlx_is_key_down(map->mlx, MLX_KEY_UP))
		player_movement_wrapper(map, 'W');
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A) || \
			mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		player_movement_wrapper(map, 'A');
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S) || \
			mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		player_movement_wrapper(map, 'S');
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D) || \
			mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		player_movement_wrapper(map, 'D');
}
