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

void	funny_sprites_render(mlx_t *mlx);
void	print_map_data(t_map *map);

int	main(int ac, char **av)
{
	t_map	*map;
	// mlx_t	*mlx;

	if (ac != 2)
		exit_message("please provide just the map file as a single argument");
	map = initialize_map(av[1]);
	ft_printf("Map seems good to me!\n");
	// mlx = mlx_init(1024, 1024, "so_long", 0);
	// if (!mlx)
	// 	exit_message("couldn't initialize MLX window");
	print_map_data(map);
	// funny_sprites_render(mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	exit(0);
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
		write(1, &map->render_categories[y * map->width], map->width);
		write(1, "\n", 1);
		y++;
	}
}

void	funny_sprites_render(mlx_t *mlx)
{
	uint8_t		**sprites;
	mlx_image_t	*img;

	sprites = read_spritesheet("sprites/dungeon_/32/dungeon_.png", 32, 15, 12);

	img = mlx_new_image(mlx, 32, 32);
	free(img->pixels);
	img->pixels = sprites[60];
	mlx_image_to_window(mlx, img, 0, 0);
}
