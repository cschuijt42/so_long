/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_content_validations.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 21:32:24 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/11 21:32:24 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// Checks the map for invalid characters, as well as for invalid start,
// exit and collectible counts. A valid map has exactly one player,
// exactly one exit and at least one collectible on it.
void	validate_map_content(t_list *map)
{
	size_t	starts;
	size_t	exits;
	size_t	collects;

	starts = 0;
	exits = 0;
	collects = 0;
	while (map)
	{
		count_row(map->content, starts, exits, collects);
		map = map->next;
	}
	if (starts != 1)
		exit(69); // replace later
	if (exits != 1)
		exit(69); // replace later
	if (collects < 1)
		exit(69); // replace later
}

void	count_row(char *row, size_t *starts, size_t *exits, size_t *collects)
{
	while (*row)
	{
		if (*row == 'P')
			*starts++;
		else if (*row == 'E')
			*exits++;
		else if (*row == 'C')
			*collects++;
		else if (*row != '1' && *row != '0')
			exit(69); // replace later
	}
}
