/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 14:16:47 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/23 14:16:47 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_sprite	*add_new_sprite(t_map *map, uint8_t **sheet, size_t index)
{
	t_sprite	*sprite;
	t_sprite	*end_of_list;

	sprite = ft_calloc(sizeof(t_sprite), 1);
	if (!sprite)
		return (NULL);
	sprite->spritesheet = sheet;
	sprite->index = index;
	sprite->image = mlx_new_image(map->mlx, 32, 32);
	sprite->animation_frames = 0;
	free(sprite->image->pixels);
	sprite->image->pixels = sheet[index];
	if (!map->sprites)
		map->sprites = sprite;
	else
	{
		end_of_list = map->sprites;
		while (end_of_list->next)
			end_of_list = end_of_list->next;
		end_of_list->next = sprite;
	}
	return (sprite);
}

t_sprite	*find_or_create_sprite(t_map *map, uint8_t **sheet, size_t index)
{
	t_sprite	*sprite;

	sprite = map->sprites;
	while (sprite)
	{
		if (sprite->index == index && sprite->spritesheet == sheet)
			return (sprite);
		if (!sprite->next)
			break ;
		sprite = sprite->next;
	}
	return (add_new_sprite(map, sheet, index));
}
