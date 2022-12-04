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
	if (map->lock_input)
		return ;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		movement_wrapper(map, 'W');
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		movement_wrapper(map, 'A');
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		movement_wrapper(map, 'S');
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		movement_wrapper(map, 'D');
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
}
