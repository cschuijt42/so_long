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

// Validates that all rows of the map are the same size and
// that the map contains at least three rows and three columns
void	validate_map_measurements(t_list *map)
{
	size_t	len;

	len = ft_strlen(map->content);
	if (len < 3 || ft_lstsize(map) < 3)
		exit(69); // Replace later
	while (map)
	{
		if (ft_strlen(map->content) != len)
			exit(80); // replace this later
		map = map->next;
	}
}

// Validates that the entire map is surrounded by walls.
void	validate_map_boundaries(t_list *map)
{
	validate_outer_row(map->content);
	validate_outer_row(ft_lstlast(map)->content);
	map = map->next;
	while (map->next)
	{
		validate_middle_row(map->content);
		map = map->next;
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
