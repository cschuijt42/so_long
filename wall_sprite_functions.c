/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_sprite_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:26:31 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/22 16:26:31 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint8_t	wall_corner(uint8_t surroundings)
{
	if ((surroundings >> 1 & 1) & (surroundings >> 3 & 1))
		return (2);
	if ((surroundings >> 3 & 1) & (surroundings >> 5 & 1))
		return (32);
	if ((surroundings >> 5 & 1) & (surroundings >> 7 & 1))
		return (30);
	return (0);
}

uint8_t	wall_single(uint8_t surroundings)
{
	if (surroundings >> 1 & 1)
		return (1);
	if (surroundings >> 3 & 1)
		return (17);
	if (surroundings >> 5 & 1)
		return (31);
	return (15);
}

uint8_t	wall_opposing(uint8_t surroundings)
{
	if (surroundings >> 1 & 1)
		return (46);
	return (18);
}

uint8_t	wall_triple(uint8_t surroundings)
{
	if (surroundings >> 1 ^ 1)
		return (33);
	if (surroundings >> 1 ^ 1)
		return (45);
	if (surroundings >> 1 ^ 1)
		return (3);
	return (47);
}

uint8_t	wall_corner_edge(uint8_t surroundings)
{
	if ((surroundings >> 1 & 1) & (surroundings >> 3 & 1))
		return (12);
	if ((surroundings >> 3 & 1) & (surroundings >> 5 & 1))
		return (40);
	if ((surroundings >> 5 & 1) & (surroundings >> 7 & 1))
		return (42);
	return (10);
}
