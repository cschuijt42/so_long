/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:15:34 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/15 15:15:34 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_sprites	*initialize_sprites(mlx_t *mlx)
{
	t_sprites		*sprites;
	unsigned int	wh[2] = {16, 16};
	unsigned int	xy[2] = {0, 64};

	sprites = malloc(sizeof(t_sprites));
	if (!sprites)
		exit_perror("malloc error loading sprites");
	sprites->texture = mlx_load_png("sprites/dungeon_/dungeon_.png");
	sprites->wall = mlx_texture_area_to_image(mlx, sprites->texture, xy, wh);
	return (sprites);
}

void	render_map(t_map *map, mlx_t *mlx)
{
	size_t		i;
	t_sprites	*sprites;

	i = 0;
	sprites = initialize_sprites(mlx);
	while (map->content[i])
	{
		if (map->content[i] == '1')
		{
			mlx_image_to_window(mlx, sprites->wall, i % map->row_length * TILE_S * TILE_M, i / map->row_length * TILE_S * TILE_M);
		}
		i++;
	}
}
