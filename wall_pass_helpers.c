/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_pass_helpers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 22:09:28 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/21 22:09:28 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static uint8_t	get_sprite_from_surroundings(uint8_t s);
static uint8_t	get_wall_sprite_from_surroundings(uint8_t s);
static uint8_t	get_edge_sprite_from_surroundings(uint8_t s);
static int		is_o(char c);

unsigned char	determine_wall_sprite(t_map *map, size_t i)
{
	unsigned char	surroundings;
	size_t			size;
	size_t			width;

	surroundings = 0;
	size = map->size;
	width = map->width;
	if (i >= width + 1 && is_o(map->sprite_categories[i - width - 1]))
		surroundings |= 1;
	if (i >= width && is_o(map->sprite_categories[i - width]))
		surroundings |= 1 << 1;
	if (i >= width - 1 && is_o(map->sprite_categories[i - width + 1]))
		surroundings |= 1 << 2;
	if (i < size - 1 && is_o(map->sprite_categories[i + 1]))
		surroundings |= 1 << 3;
	if (i <= size - width - 1 && is_o(map->sprite_categories[i + width + 1]))
		surroundings |= 1 << 4;
	if (i <= size - width && is_o(map->sprite_categories[i + width]))
		surroundings |= 1 << 5;
	if (i <= size - width + 1 && is_o(map->sprite_categories[i + width - 1]))
		surroundings |= 1 << 6;
	if (i >= 1 && is_o(map->sprite_categories[i - 1]))
		surroundings |= 1 << 7;
	return (get_sprite_from_surroundings(surroundings));
}

static uint8_t	get_sprite_from_surroundings(uint8_t s)
{
	if ((s >> 1 & 1) | (s >> 3 & 1) | (s >> 5 & 1) | (s >> 7 & 1))
		return (get_wall_sprite_from_surroundings(s));
	return (get_edge_sprite_from_surroundings(s));
}

static uint8_t	get_wall_sprite_from_surroundings(uint8_t s)
{
	if (check_against_bitmask(s, "*1*000*1", 4))
		return (wall_corner(s));
	if (check_against_bitmask(s, "*1*00000", 4))
		return (wall_single(s));
	if (check_against_bitmask(s, "*0*1*0*1", 2))
		return (wall_opposing(s));
	if (check_against_bitmask(s, "*1*1*0*1", 4))
		return (wall_triple(s));
	if (check_against_bitmask(s, "*1*010*1", 4))
		return (wall_corner_edge(s));
	if (check_against_bitmask(s, "*1*01010", 4))
		return (wall_single_edge_lr(s));
	if (check_against_bitmask(s, "*1*00010", 4))
		return (wall_single_edge_l(s));
	if (check_against_bitmask(s, "*1*01000", 4))
		return (wall_single_edge_r(s));
	if (check_against_bitmask(s, "*1*1*1*1", 1))
		return (48);
	return (0);
}

static uint8_t	get_edge_sprite_from_surroundings(uint8_t s)
{
	if (check_against_bitmask(s, "10000000", 4))
		return (edge_single(s));
	if (check_against_bitmask(s, "10100000", 4))
		return (edge_consecutive(s));
	if (check_against_bitmask(s, "10001000", 2))
		return (edge_opposing(s));
	if (check_against_bitmask(s, "10101000", 4))
		return (edge_triple(s));
	if (check_against_bitmask(s, "10101010", 1))
		return (26);
	return (0);
}

static int	is_o(char c)
{
	return (c == 'N' || c == 'F' || c == 'L' || c == 'P');
}
