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

t_list	*read_map(char *path)
{
	int		fd;
	t_list	*map;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(69); // replace this later
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(&map, ft_lstnew(line));
		else
			break ;
	}
	close(fd);
	ft_lstiter(map, &lstiter_remove_newline);
	validate_map_measurements(map);
	validate_map_boundaries(map);
	validate_map_content(map);
	return (map);
}

static void	lstiter_remove_newline(void *ptr)
{
	char	*str;

	str = (char *) ptr;
	while (*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}
