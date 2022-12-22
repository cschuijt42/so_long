/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_name.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 22:59:08 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/22 22:59:08 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_in_map_name(t_map *map, char *path)
{
	char	**split_path;
	char	*file_name;
	size_t	index;

	split_path = ft_split(path, '/');
	if (!split_path)
		exit_perror("malloc error");
	index = 0;
	while (split_path[index])
		index++;
	file_name = ft_strdup(split_path[index - 1]);
	if (!file_name)
		exit_perror("malloc error");
	free_array((void **)split_path);
	map->map_name = file_name;
}
