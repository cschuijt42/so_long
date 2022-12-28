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

#ifndef PATROLS

void	load_patrols(t_map *map)
{
	(void) map;
	return ;
}

#else

void	load_patrols(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->content[i])
	{
		if (should_be_patrol(map->content[i]))
			add_patrol_to_map(map, i, map->content[i]);
		i++;
	}
}

#endif

void	add_patrol_to_map(t_map *map, size_t pos, char dir)
{
	t_patrol	*patrol;
	t_patrol	*last_patrol;

	patrol = ft_calloc(sizeof(t_patrol), 1);
	if (!patrol)
		exit_perror("malloc error");
	patrol->pos = pos;
	if (dir == 'U')
		patrol->move_direction = 0;
	else if (dir == 'R')
		patrol->move_direction = 1;
	else if (dir == 'D')
		patrol->move_direction = 2;
	else if (dir == 'L')
	{
		patrol->move_direction = 3;
		patrol->facing_offset = 4;
	}
	last_patrol = map->patrols;
	while (last_patrol->next)
		last_patrol = last_patrol->next;
	last_patrol->next = patrol;
}

int	should_be_patrol(char c)
{
	return (c == 'U' || c == 'D' || c == 'L' || c == 'R');
}
