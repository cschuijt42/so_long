/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameplay_checks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 20:13:01 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/04 20:13:01 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_pick_up_collectible(t_map *map, size_t pos)
{
	t_collectible	*collectible;
	t_sprite		*sprite;

	collectible = map->collectibles;
	while (collectible)
	{
		if (collectible->pos == pos)
		{
			collectible->picked_up = true;
			sprite = find_or_create_sprite(map, map->wall_sprites, 178);
			sprite->image->instances[collectible->instance].enabled = false;
			return ;
		}
		collectible = collectible->next;
	}
}

void	try_exit_map(t_map *map)
{
	t_collectible	*collectible;

	collectible = map->collectibles;

	while (collectible)
	{
		if (!collectible->picked_up)
			return ;
		collectible = collectible->next;
	}
	ft_printf("Game over at %d moves\n", map->player->moves_taken);
	mlx_close_window(map->mlx);
}
