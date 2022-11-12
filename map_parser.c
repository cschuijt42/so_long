/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:29:03 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/11 14:29:03 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

char	*initialize_map(char *path)
{
	int		fd;
	char	*map;
	char	**map_rows;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(69); // replace this later
	map = read_map_from_file(path);
	close(fd);
	map_rows = ft_split(map,'\n');
	if (!map_rows)
		exit(90); // replace later
	validate_map_measurements(map_rows);
	validate_map_boundaries(map_rows);
	validate_map_content(map);
	return (map);
}

// Returns the entire map as a string, without newlines stripped.
char	*read_map_from_file(int fd)
{
	char	*map;
	char	*map2;
	char	*line;

	map = ft_calloc(1, 1);
	if (!map)
		exit(90); // replace later
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map2 = ft_strjoin(map, line);
			if (!map2)
				exit(90); // replace later
			free(map);
			free(line);
			map = map2;
		}
		else
			break ;
	}
	return (map);
}
