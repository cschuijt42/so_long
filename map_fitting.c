/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_fitting.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/25 16:45:33 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/25 16:45:33 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	fit_map_array_to_window(char ***map_array)
{
	size_t	missing_width;
	size_t	original_width;
	size_t	i;
	char	*str;

	add_top_row(map_array);
	i = 0;
	original_width = ft_strlen((*map_array)[i]);
	if (original_width >= MIN_MAP_W)
		return ;
	missing_width = MIN_MAP_W - original_width;
	while ((*map_array)[i])
	{
		str = ft_calloc(MIN_MAP_W + 1, 1);
		if (!str)
			exit_perror("malloc error");
		ft_memset(str, '1', MIN_MAP_W);
		ft_memcpy(str + (missing_width / 2), (*map_array)[i], original_width);
		free((*map_array)[i]);
		(*map_array)[i] = str;
		i++;
	}
}

void	add_top_row(char ***map_array)
{
	size_t	i;
	size_t	row_size;
	char	**new_array;

	i = 0;
	row_size = ft_strlen(*map_array[0]);
	while ((*map_array)[i])
		i++;
	new_array = ft_calloc(sizeof(char *), i + 2);
	if (!new_array)
		exit_perror("malloc error");
	new_array[0] = ft_calloc(1, row_size + 1);
	if (!new_array[0])
		exit_perror("malloc error");
	ft_memset(new_array[0], '1', row_size);
	i = 0;
	while ((*map_array)[i])
	{
		new_array[i + 1] = (*map_array)[i];
		i++;
	}
	free(*map_array);
	*map_array = new_array;
}
