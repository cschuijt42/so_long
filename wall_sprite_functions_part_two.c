/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_sprite_functions_part_two.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:26:23 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/22 16:26:23 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint8_t	wall_single_edge_lr(uint8_t surroundings)
{
	if (surroundings >> 1 & 1)
		return (11);
	if (surroundings >> 3 & 1)
		return (27);
	if (surroundings >> 5 & 1)
		return (41);
	return (25);
}

uint8_t	wall_single_edge_l(uint8_t surroundings)
{
	if (surroundings >> 1 & 1)
		return (39);
	if (surroundings >> 3 & 1)
		return (24);
	if (surroundings >> 5 & 1)
		return (53);
	return (8);
}

uint8_t	wall_single_edge_r(uint8_t surroundings)
{
	if (surroundings >> 1 & 1)
		return (38);
	if (surroundings >> 3 & 1)
		return (9);
	if (surroundings >> 5 & 1)
		return (54);
	return (23);
}
