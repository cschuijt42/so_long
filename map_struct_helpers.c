/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_struct_helpers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 17:17:15 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/27 17:17:15 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_additional_map_variables(t_map *map, size_t player_pos)
{
	map->size = ft_strlen(map->content);
	map->content[player_pos] = '0';
	map->col_total = ft_strchrc(map->content, 'C');
	map->col_total_str = ft_itoa(map->col_total);
	if (!map->col_total_str)
		exit_perror("malloc error");
	map->movement_clock = 20;
}
