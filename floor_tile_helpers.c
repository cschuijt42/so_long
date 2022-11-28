/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_tile_helpers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 13:42:20 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/28 13:42:20 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_floortile	*initialize_tile_list(void)
{
	t_floortile	*list;

	list = NULL;
	add_tile_to_list(&list, "@@@\0\0");
	add_tile_to_list(&list, "O\0\0\0\0");
	return (list);
}

t_floortile	*add_tile_to_list(t_floortile **list, char *pattern)
{
	t_floortile	*newtile;
	t_floortile	*start;
	t_floortile	*last;

	start = *list;
	newtile = new_tile(pattern);
	if (*list == NULL)
	{
		*list = newtile;
		newtile->next = newtile;
	}
	else
	{
		last = *list;
		while (last->next != start)
			last = last->next;
		last->next = newtile;
		newtile->next = *list;
	}
	return (newtile);
}

t_floortile	*new_tile(char *pattern)
{
	t_floortile	*tile;

	tile = ft_calloc(1, sizeof(t_floortile));
	if (!tile)
		return (NULL);
	tile->pattern = ft_calloc(5, 1);
	if (!tile->pattern)
	{
		free(tile);
		return (NULL);
	}
	ft_memmove(tile->pattern, pattern, 5);
	return (tile);
}

void	free_tile_list(t_floortile **list)
{
	t_floortile	*start;
	t_floortile	*next;

	start = *list;
	while (*list)
	{
		free((*list)->pattern);
		next = (*list)->next;
		free(*list);
		*list = next;
		if (*list == start)
			break ;
	}
	*list = NULL;
}
