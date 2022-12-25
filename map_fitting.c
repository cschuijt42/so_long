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

void	fit_map_array_to_window(char **map_array)
{
	size_t	missing_width;
	size_t	original_width;
	size_t	i;
	char	*str;

	i = 0;
	original_width = ft_strlen(map_array[i]);
	if (original_width >= WINDOW_MIN_W)
		return ;
	missing_width = WINDOW_MIN_W - original_width;
	while (map_array[i])
	{
		str = ft_calloc(WINDOW_MIN_W + 1, 1);
		if (!str)
			exit_perror("malloc error");
		ft_memset(str, '1', WINDOW_MIN_W);
		ft_memcpy(str + (missing_width / 2), map_array[i], original_width);
		free(map_array[i]);
		map_array[i] = str;
		i++;
	}
}
