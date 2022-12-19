/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shadow_pass.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 13:15:21 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/01 13:15:21 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	determine_shadow_sprites(t_map *map)
{
	size_t	i;

	map->render_shadows = ft_calloc(1, map->size + 1);
	if (!map->render_shadows)
		exit_perror("malloc error");
	i = map->width;
	while (i < map->size - map->width)
	{
		if (map->sprite_categories[i] == 'F' && should_have_shadow(map, i))
			fill_in_floor_shadow(map, i);
		if (map->sprite_categories[i] == 'L' && should_have_shadow(map, i))
		{
			if (is_wall(map, i - map->width - 1))
			{
				if (is_wall(map, i - 1))
					map->render_shadows[i] = 14;
				else
					map->render_shadows[i] = 25;
			}
			else
				map->render_shadows[i] = 15;
		}
		i++;
	}
}

void	render_shadows(t_map *map)
{
	size_t	i;

	determine_shadow_sprites(map);
	i = map->width;
	while (i < map->size - map->width)
	{
		if (should_have_shadow(map, i))
			render_shadow_sprite(map, i);
		i++;
	}
}

int	should_have_shadow(t_map *map, size_t i)
{
	if (!is_floor_or_lava(map, i))
		return (0);
	if (is_wall(map, i - map->width - 1))
		return (1);
	if (is_wall(map, i - map->width))
		return (1);
	if (is_wall(map, i - 1))
		return (1);
	return (0);
}

int	is_wall(t_map *map, size_t i)
{
	char	c;

	c = map->sprite_categories[i];
	return (c == 'W' || c == 'N');
}

int	is_floor_or_lava(t_map *map, size_t i)
{
	char	c;

	c = map->sprite_categories[i];
	return (c == 'F' || c == 'L');
}
