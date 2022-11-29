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
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x5E\x5F\0\0\0"); // 2x1 dark tiles
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x41\0\0\x50\0"); // 1x2 dark tiles
	add_tile_to_list(&list, "\x40\0\0\0\0"); // single quad dark tile
	add_tile_to_list(&list, "\x60\0\x70\x6F\0"); // dark corner bottom left
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x44\x45\x54\0\0"); // dark corner top right
	add_tile_to_list(&list, "\x52\x53\x62\x61\0"); // 2x2 dark square
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x63\0\0\x72\x71"); // dark corner bottom right
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
	add_tile_to_list(&list, "\x9A\0\0\0\0"); // single light tile
	add_tile_to_list(&list, "\x42\x43\0\x51\0"); // dark corner top left
	add_tile_to_list(&list, "\x4F\0\0\0\0"); // single dark tile
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
