/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:28:55 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/11 14:28:55 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_map	*map;
	mlx_t	*mlx;

	if (ac != 2)
		exit_message("please provide just the map file as a single argument");
	map = initialize_map(av[1]);
	ft_printf("Map seems good to me!\n");
	mlx = mlx_init(map->row_length * TILE_S, map->rows * TILE_S, "so_long", 0);
	if (!mlx)
		exit_message("couldn't initialize MLX window");
	render_map(map, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(0);
	return (0);
}
