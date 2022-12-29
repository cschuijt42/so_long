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
#include <stdlib.h>

void	render_gui(t_map *map)
{
	size_t	i;

	sprite_buffer_to_image(map->gui_bg_sprites[0], map->background, 16, 16);
	sprite_buffer_to_image(map->gui_bg_sprites[3], map->background, 16, 48);
	sprite_buffer_to_image(map->gui_bg_sprites[6], map->background, 16, 80);
	i = 1;
	while (i < map->width - 2)
	{
		sprite_buffer_to_image(map->gui_bg_sprites[1], \
								map->background, (i * 32) + 16, 16);
		sprite_buffer_to_image(map->gui_bg_sprites[4], \
								map->background, (i * 32) + 16, 48);
		sprite_buffer_to_image(map->gui_bg_sprites[7], \
								map->background, (i * 32) + 16, 80);
		i++;
	}
	sprite_buffer_to_image(map->gui_bg_sprites[2], map->background, \
							(i * 32) + 16, 16);
	sprite_buffer_to_image(map->gui_bg_sprites[5], map->background, \
							(i * 32) + 16, 48);
	sprite_buffer_to_image(map->gui_bg_sprites[8], map->background, \
							(i * 32) + 16, 80);
	render_gui_static_strings(map);
	initialize_gui_dynamic_strings(map);
	render_gui_dynamic_strings(map);
}

void	render_gui_static_strings(t_map *map)
{
	size_t	xy[2];

	xy[0] = 36;
	xy[1] = 26;
	string_to_image(map->map_name, map->background, map->gui_charset, xy);
	xy[0] = 36;
	xy[1] = 50;
	string_to_image("Moves:", map->background, map->gui_charset, xy);
	xy[0] = 36;
	xy[1] = 74;
	string_to_image("Gold:", map->background, map->gui_charset, xy);
}

void	render_gui_dynamic_strings(t_map *map)
{
	size_t	collectible_offset;
	char	*str;
	size_t	xy[2];

	collectible_offset = (ft_digitcount(map->col_grabbed) + 1) * FONT_W;
	xy[0] = 0;
	xy[1] = 0;
	str = ft_itoa(map->player->moves_taken);
	if (!str)
		exit_perror("malloc error");
	string_to_image(str, map->move_counter, map->gui_charset, xy);
	free(str);
	str = ft_itoa(map->col_grabbed);
	if (!str)
		exit_perror("malloc error");
	xy[0] = 0;
	xy[1] = 0;
	string_to_image(str, map->col_counter, map->gui_charset, xy);
	xy[0] = collectible_offset;
	xy[1] = 0;
	string_to_image("/", map->col_counter, map->gui_charset, xy);
	xy[0] += FONT_W;
	xy[1] = 0;
	string_to_image(map->col_total_str, map->col_counter, map->gui_charset, xy);
	free(str);
}

void	initialize_gui_dynamic_strings(t_map *map)
{
	size_t	instance;

	if (!map->move_counter)
	{
		map->move_counter = mlx_new_image(map->mlx, 300, 32);
		instance = mlx_image_to_window(map->mlx, map->move_counter, 115, 50);
		mlx_set_instance_depth(&map->move_counter->instances[instance], \
								layer_gui_moves);
	}
	if (!map->col_counter)
	{
		map->col_counter = mlx_new_image(map->mlx, 300, 32);
		instance = mlx_image_to_window(map->mlx, map->col_counter, 104, 74);
		mlx_set_instance_depth(&map->col_counter->instances[instance], \
								layer_gui_cols);
	}
}

void	update_gui(t_map *map)
{
	ft_memset((void *)map->move_counter->pixels, '\0', 32 * 300 * 4);
	ft_memset((void *)map->col_counter->pixels, '\0', 32 * 300 * 4);
	render_gui_dynamic_strings(map);
}
