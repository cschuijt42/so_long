/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 17:38:25 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/23 17:38:25 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	render_x_pos(t_map *map, size_t i)
{
	return ((i % map->width) * 32);
}

size_t	render_y_pos(t_map *map, size_t i)
{
	return (((i / map->width) * 32) + GUI_OFFSET);
}
