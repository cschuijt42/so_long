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

void	validate_map_measurements(t_list *map)
{
}

void	validate_map_row_length(t_list *map)
{
	size_t	len;

	len = ft_strlen(map->content);
	while (map)
	{
		if (ft_strlen(map->content) != len)
			exit(80); // replace this later
		map = map->next;
	}
}
