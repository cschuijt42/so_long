/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lava_pass.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:48:15 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/25 13:48:15 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wall_or_lava(char c);

uint8_t	determine_lava_sprite(t_map *map, size_t i)
{
	uint8_t	surroundings;

	surroundings = 0;
	if (is_wall_or_lava(map->sprite_categories[i - map->width]))
		surroundings |= 1 << 1;
	if (is_wall_or_lava(map->sprite_categories[i + 1]))
		surroundings |= 1 << 3;
	if (is_wall_or_lava(map->sprite_categories[i + map->width]))
		surroundings |= 1 << 5;
	if (is_wall_or_lava(map->sprite_categories[i - 1]))
		surroundings |= 1 << 7;
	if (surroundings > 50)
		return (match_high_lava_sprites(surroundings));
	else
		return (match_low_lava_sprites(surroundings));
}

uint8_t	match_high_lava_sprites(uint8_t surroundings)
{
	if (surroundings == 128)
		return (24);
	if (surroundings == 130)
		return (52);
	if (surroundings == 138)
		return (76);
	if (surroundings == 136)
		return (1);
	if (surroundings == 160)
		return (40);
	if (surroundings == 162)
		return (88);
	if (surroundings == 168)
		return (64);
	if (surroundings == 170)
		return (68);
	return (6);
}

uint8_t	match_low_lava_sprites(uint8_t surroundings)
{
	if (surroundings == 2)
		return (36);
	if (surroundings == 8)
		return (48);
	if (surroundings == 10)
		return (28);
	if (surroundings == 32)
		return (12);
	if (surroundings == 34)
		return (0);
	if (surroundings == 40)
		return (16);
	if (surroundings == 42)
		return (100);
	return (6);
}

static int	is_wall_or_lava(char c)
{
	return (c == 'W' || c == 'N' || c == 'L');
}
