/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_rendering.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 16:19:37 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/29 16:19:37 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_collectibles(t_map *map)
{
	t_collectible	*collectible;
	mlx_instance_t	*instance;
	t_sprite		*sprite;

	collectible = map->collectibles;
	sprite = find_or_create_sprite(map, map->bg_sprites, 178);
	while (collectible)
	{
		collectible->instance = mlx_image_to_window(map->mlx, sprite->image, \
		render_x_pos(map, collectible->pos), \
		render_y_pos(map, collectible->pos));
		instance = &sprite->image->instances[collectible->instance];
		mlx_set_instance_depth(instance, layer_collectibles);
		collectible = collectible->next;
	}
}
