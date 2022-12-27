/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_solvability.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 13:31:18 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/13 13:31:18 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static size_t	traverse_map_string(char *str, t_map *map);
static void		move_into_space(char *space);
static size_t	remaining_objectives(char *map);

void	validate_map_solvability(t_map *map)
{
	char	*map_str;
	size_t	i;

	map_str = ft_strdup(map->content);
	if (!map_str)
		exit_perror("malloc error");
	map_str[map->player->pos] = 'X';
	i = 1;
	while (i)
		i = traverse_map_string(map_str, map);
	if (remaining_objectives(map_str))
		exit_message("map has unreachable exit or collectibles");
	free(map_str);
}

static size_t	traverse_map_string(char *str, t_map *map)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == 'X')
		{
			i++;
			*str = 'x';
			move_into_space(str + 1);
			move_into_space(str - 1);
			move_into_space(str + map->width);
			move_into_space(str - map->width);
		}
		str++;
	}
	return (i);
}

#ifdef PATROLS

static void	move_into_space(char *space)
{
	if (*space == '0' || *space == 'C' || *space == 'P' || *space == 'E')
	{
		*space = 'X';
	}
	if (*space == 'U' || *space == 'D' || *space == 'L' || *space == 'R')
	{
		*space = 'X';
	}
}

#else

static void	move_into_space(char *space)
{
	if (*space == '0' || *space == 'C' || *space == 'P' || *space == 'E')
	{
		*space = 'X';
	}
}

#endif

static size_t	remaining_objectives(char *map)
{
	size_t	i;

	i = 0;
	while (*map)
	{
		if (*map == 'C' || *map == 'P' || *map == 'E')
			i++;
		map++;
	}
	return (i);
}
