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
#include <unistd.h>

void	print_map_data(t_map *map);

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		exit_message("please provide just the map file as a single argument");
	map = initialize_map(av[1]);
	ft_printf("Map seems good to me!\n");
	map->mlx = mlx_init(32 * map->width, 32 * map->height, "so_long", 0);
	if (!map->mlx)
		exit_message("couldn't initialize MLX window");
	categorize_map_walls(map);
	fill_in_background_sprite_indexes(map);
	print_map_data(map);
	mlx_loop_hook(map->mlx, &animate_player_hook, map);
	mlx_loop_hook(map->mlx, &key_hook, map);
	render_map(map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (0);
}

void	print_map_data(t_map *map)
{
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		write(1, &map->content[y * map->width], map->width);
		write(1, "\n", 1);
		y++;
	}
	write(1, "\n", 1);
	y = 0;
	while (y < map->height)
	{
		write(1, &map->sprite_categories[y * map->width], map->width);
		write(1, "\n", 1);
		y++;
	}
}
