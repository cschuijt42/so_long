/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 00:00:31 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/04 00:00:31 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player_hook(void *map_ptr)
{
	static int		clock = 0;
	static int		offset = 0;
	t_map			*map;

	map = (t_map *) map_ptr;
	clock++;
	if (clock >= 15)
	{
		clock = 0;
		offset++;
		if (offset > 3)
			offset = 0;
		map->player->image->pixels = map->player_sprites[offset + 4];
	}
}
