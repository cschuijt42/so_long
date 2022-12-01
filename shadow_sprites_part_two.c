/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shadow_sprites_part_two.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 17:47:20 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/01 17:47:20 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	continuous_n_floor_shadow(t_map *map, size_t i)
{
	size_t	sprite;

	sprite = (size_t)(unsigned char) map->render_terrain[i];
	if (sprite == 64)
		map->render_shadows[i] = 5;
	if (sprite == 79 || sprite == 154 || sprite == 65)
		map->render_shadows[i] = 6;
	if (sprite == 96 || sprite == 99)
		map->render_shadows[i] = 6;
	if (sprite == 94 || sprite == 82 || sprite == 68 || sprite == 66)
		map->render_shadows[i] = 7;
	if (sprite == 113)
		map->render_shadows[i] = 7;
	if (sprite == 95 || sprite == 83 || sprite == 69 || sprite == 67)
		map->render_shadows[i] = 8;
}

void	ending_n_floor_shadow(t_map *map, size_t i)
{
	size_t	sprite;

	sprite = (size_t)(unsigned char) map->render_terrain[i];
	if (sprite == 64)
		map->render_shadows[i] = 20;
	else if (sprite == 94 || sprite == 82 || sprite == 68)
		map->render_shadows[i] = 22;
	else if (sprite == 66 || sprite == 113)
		map->render_shadows[i] = 22;
	else
		map->render_shadows[i] = 21;
}

void	continuous_w_floor_shadow(t_map *map, size_t i)
{
	size_t	sprite;

	sprite = (size_t)(unsigned char) map->render_terrain[i];
	if (sprite == 64)
		map->render_shadows[i] = 10;
	if (sprite == 79 || sprite == 154 || sprite == 94)
		map->render_shadows[i] = 11;
	if (sprite == 68 || sprite == 113)
		map->render_shadows[i] = 11;
	if (sprite == 65 || sprite == 82 || sprite == 96)
		map->render_shadows[i] = 12;
	if (sprite == 66 || sprite == 99)
		map->render_shadows[i] = 12;
	if (sprite == 80 || sprite == 97 || sprite == 111 || sprite == 81)
		map->render_shadows[i] = 13;
}

void	ending_w_floor_shadow(t_map *map, size_t i)
{
	size_t	sprite;

	sprite = (size_t)(unsigned char) map->render_terrain[i];
	if (sprite == 65 || sprite == 82 || sprite == 96)
		map->render_shadows[i] = 21;
	else if (sprite == 66 || sprite == 99)
		map->render_shadows[i] = 16;
	else
		map->render_shadows[i] = 15;
}
