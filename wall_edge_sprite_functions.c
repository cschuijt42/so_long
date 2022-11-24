/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_edge_sprite_functions.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:24:00 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/22 16:24:00 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint8_t	edge_single(uint8_t surroundings)
{
	if (surroundings >> 0 & 1)
		return (20);
	if (surroundings >> 2 & 1)
		return (19);
	if (surroundings >> 4 & 1)
		return (4);
	return (5);
}

uint8_t	edge_consecutive(uint8_t surroundings)
{
	if ((surroundings >> 0 & 1) & (surroundings >> 2 & 1))
		return (50);
	if ((surroundings >> 2 & 1) & (surroundings >> 4 & 1))
		return (22);
	if ((surroundings >> 4 & 1) & (surroundings >> 6 & 1))
		return (35);
	return (21);
}

uint8_t	edge_opposing(uint8_t surroundings)
{
	if (surroundings >> 0 & 1)
		return (34);
	return (49);
}

uint8_t	edge_triple(uint8_t surroundings)
{
	if (!(surroundings >> 0 & 1))
		return (52);
	if (!(surroundings >> 2 & 1))
		return (51);
	if (!(surroundings >> 4 & 1))
		return (36);
	return (37);
}
