/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 22:51:14 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/22 22:51:14 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_gui(t_map *map)
{
	size_t	i;

	sprite_buffer_to_image(map->gui_bg_sprites[0], map->background, 0, 0);
	sprite_buffer_to_image(map->gui_bg_sprites[3], map->background, 0, 32);
	sprite_buffer_to_image(map->gui_bg_sprites[6], map->background, 0, 64);
	i = 1;
	while (i < map->width - 1)
	{
		sprite_buffer_to_image(map->gui_bg_sprites[1], \
								map->background, i * 32, 0);
		sprite_buffer_to_image(map->gui_bg_sprites[4], \
								map->background, i * 32, 32);
		sprite_buffer_to_image(map->gui_bg_sprites[7], \
								map->background, i * 32, 64);
		i++;
	}
	sprite_buffer_to_image(map->gui_bg_sprites[2], map->background, i * 32, 0);
	sprite_buffer_to_image(map->gui_bg_sprites[5], map->background, i * 32, 32);
	sprite_buffer_to_image(map->gui_bg_sprites[8], map->background, i * 32, 64);
}

void	update_gui(t_map *map)
{
	(void) map;
}
