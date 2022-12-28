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

int	run_gameplay_checks(t_map *map)
{
	if (player_next_to_patrol(map))
		return (game_over(map, 0));
	if (map->content[map->player->pos] == 'C')
		try_pick_up_collectible(map, map->player->pos);
	if (map->content[map->player->pos] == 'E')
		if (try_exit_map(map))
			return (game_over(map, 1));
	ft_printf("Moves: %d\n", map->player->moves_taken);
	return (0);
}

void	try_pick_up_collectible(t_map *map, size_t pos)
{
	t_collectible	*collectible;
	t_sprite		*sprite;

	collectible = map->collectibles;
	while (collectible)
	{
		if (collectible->pos == pos && !(collectible->picked_up))
		{
			collectible->picked_up = true;
			sprite = find_or_create_sprite(map, map->bg_sprites, 178);
			sprite->image->instances[collectible->instance].enabled = false;
			map->col_grabbed++;
			return ;
		}
		collectible = collectible->next;
	}
}

int	try_exit_map(t_map *map)
{
	t_collectible	*collectible;

	collectible = map->collectibles;
	while (collectible)
	{
		if (!collectible->picked_up)
			return (0);
		collectible = collectible->next;
	}
	return (1);
}

int	player_next_to_patrol(t_map *map)
{
	size_t		personal_space[5];
	t_patrol	*patrol;

	personal_space[0] = map->player->pos;
	personal_space[1] = map->player->pos + 1;
	personal_space[2] = map->player->pos - 1;
	personal_space[3] = map->player->pos + map->width;
	personal_space[4] = map->player->pos - map->width;
	patrol = map->patrols;
	while (patrol)
	{
		if (patrol->pos == personal_space[0] || \
			patrol->pos == personal_space[1] || \
			patrol->pos == personal_space[2] || \
			patrol->pos == personal_space[3] || \
			patrol->pos == personal_space[4])
		{
			return (1);
		}
		patrol = patrol->next;
	}
	return (0);
}

int	game_over(t_map *map, int victory)
{
	if (victory)
	{
		ft_printf("Victory at %d moves\n", map->player->moves_taken);
		mlx_close_window(map->mlx);
	}
	else
	{
		ft_printf("Game over at %d moves\n", map->player->moves_taken);
		mlx_close_window(map->mlx);
	}
	return (1);
}
