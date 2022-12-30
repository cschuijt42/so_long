/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_end.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 15:19:52 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/30 15:19:52 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endscreen_hook(void *map_ptr)
{
	t_map		*map;
	static int	rendered_endscreen = 0;

	map = (t_map *) map_ptr;
	if (map->game_state == state_playing)
		return ;
	if (map->game_state == state_victory && rendered_endscreen == 0)
	{
		render_victory_screen(map);
		rendered_endscreen = 1;
	}
	else if (map->game_state == state_game_over && rendered_endscreen == 0)
	{
		render_game_over_screen(map);
		rendered_endscreen = 1;
	}
}

void	render_victory_screen(t_map *map)
{
	mlx_image_t	*image;
	size_t		instance;

	image = mlx_new_image(map->mlx, 256, 96);
	instance = mlx_image_to_window(map->mlx, image, \
				(map->mlx->width / 2) - 128, (map->mlx->height / 2) - 48);
	render_endscreen_background(map, image);
	string_to_image_center("You win!", image, map->gui_charset, 15);
	string_to_image_center("Press ESC to", image, map->gui_charset, 35);
	string_to_image_center("quit the game.", image, map->gui_charset, 48);
	mlx_set_instance_depth(&image->instances[instance], layer_endscreen);
}

void	render_game_over_screen(t_map *map)
{
	mlx_image_t	*image;
	size_t		instance;

	image = mlx_new_image(map->mlx, 256, 96);
	instance = mlx_image_to_window(map->mlx, image, \
				(map->mlx->width / 2) - 128, (map->mlx->height / 2) - 48);
	render_endscreen_background(map, image);
	string_to_image_center("Game over!", image, map->gui_charset, 15);
	string_to_image_center("Press ESC to", image, map->gui_charset, 35);
	string_to_image_center("quit the game.", image, map->gui_charset, 48);
	mlx_set_instance_depth(&image->instances[instance], layer_endscreen);
}

void	render_endscreen_background(t_map *map, mlx_image_t *image)
{
	size_t	i;

	sprite_buffer_to_image(map->gui_end_sprites[0], image, 0, 0);
	sprite_buffer_to_image(map->gui_end_sprites[3], image, 0, 32);
	sprite_buffer_to_image(map->gui_end_sprites[6], image, 0, 64);
	i = 1;
	while (i < 7)
	{
		sprite_buffer_to_image(map->gui_end_sprites[1], \
								image, (i * 32), 0);
		sprite_buffer_to_image(map->gui_end_sprites[4], \
								image, (i * 32), 32);
		sprite_buffer_to_image(map->gui_end_sprites[7], \
								image, (i * 32), 64);
		i++;
	}
	sprite_buffer_to_image(map->gui_end_sprites[2], image, \
							(i * 32), 0);
	sprite_buffer_to_image(map->gui_end_sprites[5], image, \
							(i * 32), 32);
	sprite_buffer_to_image(map->gui_end_sprites[8], image, \
							(i * 32), 64);
}
