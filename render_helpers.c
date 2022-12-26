/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 17:38:25 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/23 17:38:25 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	render_x_pos(t_map *map, size_t i)
{
	return ((i % map->width) * 32);
}

size_t	render_y_pos(t_map *map, size_t i)
{
	return (((i / map->width) * 32) + GUI_OFFSET);
}

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
		mlx_set_instance_depth(instance, 3);
		collectible = collectible->next;
	}
}
