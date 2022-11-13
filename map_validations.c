/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 16:45:17 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/11 16:45:17 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	validate_outer_row(char *row);
static void	validate_middle_row(char *row);

// Validates that all rows of the map are the same size and
// that the map contains at least three rows and three columns
void	validate_map_measurements(char **map)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(map[i]);
	if (len < 3)
		exit(69); // Replace later
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			exit(80); // replace this later
		i++;
	}
	if (i < 3)
		exit(69);
}

// Validates that the entire map is surrounded by walls.
void	validate_map_boundaries(char **map)
{
	size_t	i;

	i = 0;
	validate_outer_row(map[i]);
	validate_outer_row(last_string_in_array(map));
	i++;
	while (map[i] && map[i+1])
	{
		validate_middle_row(map[i]);
		i++;
	}
}

static void	validate_outer_row(char *row)
{
	while (*row)
	{
		if (*row != '1')
			exit(69); // replace later
		row++;
	}
}

static void	validate_middle_row(char *row)
{
	if (*row != '1')
		exit(69); // replace later
	row++;
	while (*row)
		row++;
	row--;
	if (*row != '1')
		exit(69); // replace later
}

// Checks the map for invalid characters, as well as for invalid start,
// exit and collectible counts. A valid map has exactly one player,
// exactly one exit and at least one collectible on it.
void	validate_map_content(char *map)
{
	size_t	starts;
	size_t	exits;
	size_t	collects;

	starts = 0;
	exits = 0;
	collects = 0;
	while (*map)
	{
		if (*map == 'P')
			starts++;
		else if (*map == 'E')
			exits++;
		else if (*map == 'C')
			collects++;
		else if (*map != '1' && *map != '0' && *map != '\n')
			exit(69); // replace later
		map++;
	}
	if (starts != 1)
		exit(69); // replace later
	if (exits != 1)
		exit(69); // replace later
	if (collects < 1)
		exit(69); // replace later
}
