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
		exit_message("map is too small");
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			exit_message("map rows are not all the same length");
		i++;
	}
	if (i < 3)
		exit_message("map is too small");
}

// Validates that the entire map is surrounded by walls.
void	validate_map_boundaries(char **map)
{
	size_t	i;

	i = 0;
	validate_outer_row(map[i]);
	validate_outer_row(last_string_in_array(map));
	i++;
	while (map[i] && map[i + 1])
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
			exit_message("map outer walls are not properly closed");
		row++;
	}
}

static void	validate_middle_row(char *row)
{
	if (*row != '1')
		exit_message("map outer walls are not properly closed");
	row++;
	while (*row)
		row++;
	row--;
	if (*row != '1')
		exit_message("map outer walls are not properly closed");
}
