/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrols.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 21:16:20 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/27 21:16:20 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_patrols(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->content[i])
	{
		if (should_be_patrol(map->content[i]))
			add_new_patrol(map, i, map->content[i]);
		i++;
	}
}

void	add_new_patrol(t_map *map, size_t pos, char dir)
{
	t_patrol	*patrol;

	patrol = ft_calloc(sizeof(t_patrol), 1);
	if (!patrol)
		exit_perror("malloc error");
	patrol->pos = pos;
	if (dir == 'U')
		patrol->move_direction = dir_up;
	else if (dir == 'R')
		patrol->move_direction = dir_right;
	else if (dir == 'D')
	{
		patrol->move_direction = dir_down;
		patrol->facing_offset = 4;
	}
	else if (dir == 'L')
	{
		patrol->move_direction = dir_left;
		patrol->facing_offset = 4;
	}
	add_patrol_to_map(map, patrol);
}

void	add_patrol_to_map(t_map *map, t_patrol *patrol)
{
	t_patrol	*last_patrol;

	patrol->next = NULL;
	if (!map->patrols)
		map->patrols = patrol;
	else
	{
		last_patrol = map->patrols;
		while (last_patrol->next)
			last_patrol = last_patrol->next;
		last_patrol->next = patrol;
	}
	update_patrol_movement_direction(map, patrol);
}

int	should_be_patrol(char c)
{
	return (c == 'U' || c == 'D' || c == 'L' || c == 'R');
}
