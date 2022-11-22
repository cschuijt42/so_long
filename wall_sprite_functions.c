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

t_uc	wall_corner(t_uc surroundings)
{
	if ((surroundings >> 1 & 1) & (surroundings >> 3 & 1))
		return (2);
	if ((surroundings >> 3 & 1) & (surroundings >> 5 & 1))
		return (32);
	if ((surroundings >> 5 & 1) & (surroundings >> 7 & 1))
		return (30);
	return (0);
}

t_uc	wall_single(t_uc surroundings)
{
	if (surroundings >> 1 & 1)
		return (1);
	if (surroundings >> 3 & 1)
		return (17);
	if (surroundings >> 5 & 1)
		return (31);
	return (15);
}

t_uc	wall_opposing(t_uc surroundings)
{
	if (surroundings >> 1 & 1)
		return (46);
	return (18);
}

t_uc	wall_triple(t_uc surroundings)
{
	if (surroundings >> 1 ^ 1)
		return (33);
	if (surroundings >> 1 ^ 1)
		return (45);
	if (surroundings >> 1 ^ 1)
		return (3);
	return (47);
}

t_uc	wall_corner_edge(t_uc surroundings)
{
	if ((surroundings >> 1 & 1) & (surroundings >> 3 & 1))
		return (12);
	if ((surroundings >> 3 & 1) & (surroundings >> 5 & 1))
		return (40);
	if ((surroundings >> 5 & 1) & (surroundings >> 7 & 1))
		return (42);
	return (10);
}
