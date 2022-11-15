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
#include <stdlib.h>

t_map	*initialize_map(char *path)
{
	int		fd;
	char	*map_str;
	char	**map_rows;
	t_map	*map_struct;

	validate_filename(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_perror("error opening file");
	map_str = read_map_from_file(fd);
	close(fd);
	map_rows = ft_split(map_str, '\n');
	if (!map_rows)
		exit_perror("malloc error in ft_split");
	validate_map_measurements(map_rows);
	validate_map_boundaries(map_rows);
	validate_map_content(map_str);
	map_struct = initialize_map_struct(map_rows);
	free_array((void **)map_rows);
	validate_map_solvability(map_struct);
	return (map_struct);
}

// Returns the entire map as a string, without newlines stripped.
char	*read_map_from_file(int fd)
{
	char	*map;
	char	*map2;
	char	*line;

	map = ft_calloc(1, 1);
	if (!map)
		exit_perror("malloc error");
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map2 = ft_strjoin(map, line);
			if (!map2)
				exit_perror("malloc error");
			free(map);
			free(line);
			map = map2;
		}
		else
			break ;
	}
	return (map);
}

// Exits unless the file ends in the .ber extension.
void	validate_filename(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 5)
		exit_message("invalid filename, needs to end in .ber");
	if (ft_strncmp(".ber", file + len - 4, 5))
		exit_message("invalid filename, needs to end in .ber");
}
