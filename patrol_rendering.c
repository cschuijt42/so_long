/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol_rendering.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 00:59:41 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/28 00:59:41 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	render_patrols(t_map *map)
{
	t_patrol	*patrol;
	int			xy[2];

	patrol = map->patrols;
	while (patrol)
	{
		patrol->image = mlx_new_image(map->mlx, 48, 48);
		free(patrol->image->pixels);
		patrol->image->pixels = map->patrol_sprites[patrol->facing_offset];
		xy[0] = render_x_pos(map, patrol->pos) - 8;
		xy[1] = render_y_pos(map, patrol->pos) - 24;
		mlx_image_to_window(map->mlx, patrol->image, xy[0], xy[1]);
		mlx_set_instance_depth(&patrol->image->instances[0], layer_patrols);
		patrol = patrol->next;
	}
	render_patrol_movement_indicators(map);
}

void	render_patrol_movement_indicators(t_map *map)
{
	t_patrol		*patrol;
	t_sprite		*sprite;
	mlx_instance_t	*instance;

	patrol = map->patrols;
	sprite = find_or_create_sprite(map, map->bg_sprites, 13);
	while (patrol)
	{
		patrol->indicator_instance = mlx_image_to_window(map->mlx, \
					sprite->image, \
					render_x_pos(map, patrol_indicator_pos(map, patrol)), \
					render_y_pos(map, patrol_indicator_pos(map, patrol)));
		instance = &sprite->image->instances[patrol->indicator_instance];
		mlx_set_instance_depth(instance, layer_indicators);
		patrol = patrol->next;
	}
}
