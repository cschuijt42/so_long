/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_helpers.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 17:32:48 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/30 17:32:48 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	load_map_collectibles(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->content[i])
	{
		if (map->content[i] == 'C')
			add_collectible_to_map(map, i);
		i++;
	}
}

void	add_collectible_to_map(t_map *map, size_t i)
{
	t_collectible	*collectible;
	t_collectible	*list;

	collectible = ft_calloc(1, sizeof(t_collectible));
	if (!collectible)
		exit_perror("malloc error");
	collectible->pos = i;
	if (!map->collectibles)
		map->collectibles = collectible;
	else
	{
		list = map->collectibles;
		while (list->next)
			list = list->next;
		list->next = collectible;
	}
}

void	clear_collectible_list(t_map *map)
{
	t_collectible	*collectible;
	t_collectible	*next;

	collectible = map->collectibles;
	while (collectible)
	{
		next = collectible->next;
		free(collectible);
		collectible = next;
	}
	map->collectibles = NULL;
}
