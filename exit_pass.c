/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_pass.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 13:42:41 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/30 13:42:41 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint8_t	determine_exit_sprite(t_map *map, size_t i)
{
	if (map->sprite_categories[i - 1] != 'F')
		return (167);
	return (168);
}
