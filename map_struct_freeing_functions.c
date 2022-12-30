/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_struct_freeing_functions.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 14:42:21 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/29 14:42:21 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	free_map_struct(t_map *map)
{
	free(map->map_name);
	free(map->content);
	free(map->sprite_categories);
	free(map->render_terrain);
	free(map->render_shadows);
	free(map->col_total_str);
	free_array((void **) map->bg_sprites);
	free_array((void **) map->lava_sprites);
	free_array((void **) map->shadow_sprites);
	free_array((void **) map->player_sprites);
	free_array((void **) map->patrol_sprites);
	free_array((void **) map->gui_bg_sprites);
	free_array((void **) map->gui_charset);
	free_array((void **) map->gui_end_sprites);
	free(map->player);
	free_linked_lists(map);
	free(map);
}

void	free_linked_lists(t_map *map)
{
	t_sprite		*sprite;
	t_sprite		*sprite_next;
	t_patrol		*patrol;
	t_patrol		*patrol_next;

	sprite = map->sprites;
	while (sprite)
	{
		sprite_next = sprite->next;
		free(sprite);
		sprite = sprite_next;
	}
	patrol = map->patrols;
	while (patrol)
	{
		patrol_next = patrol->next;
		free(patrol);
		patrol = patrol_next;
	}
	free_map_collectibles(map);
}

void	free_map_collectibles(t_map *map)
{
	t_collectible	*collectible;
	t_collectible	*next;

	collectible = map->collectibles;
	while (collectible)
	{
		next = collectible->next;
		free(collectible);
		collectible = next;
	}
}

void	detach_images_from_spritesheets(t_map *map)
{
	t_sprite	*sprite;
	t_patrol	*patrol;

	map->player->image->pixels = NULL;
	patrol = map->patrols;
	while (patrol)
	{
		patrol->image->pixels = NULL;
		patrol = patrol->next;
	}
	sprite = map->sprites;
	while (sprite)
	{
		sprite->image->pixels = NULL;
		sprite = sprite->next;
	}
}
