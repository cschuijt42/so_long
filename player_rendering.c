/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rendering.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 17:49:00 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/03 17:49:00 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	render_player(t_map *map)
{
	int	xy[2];

	if (!map->player->image)
	{
		map->player->image = mlx_new_image(map->mlx, 48, 48);
		free(map->player->image->pixels);
		map->player->image->pixels = map->player_sprites[4];
	}
	xy[0] = render_x_pos(map, map->player->pos) - 8;
	xy[1] = render_y_pos(map, map->player->pos) - 24;
	mlx_image_to_window(map->mlx, map->player->image, xy[0], xy[1]);
	mlx_set_instance_depth(&map->player->image->instances[0], 4);
}
