/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_struct_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 13:31:36 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/13 13:31:36 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_map	*initialize_map_struct(char **map_array)
{
	t_map	*map;
	size_t	player_pos;
	size_t	height;

	fit_map_array_to_window(&map_array);
	height = 0;
	while (map_array[height])
		height++;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit_perror("malloc error");
	map->height = height;
	map->width = ft_strlen(map_array[0]);
	map->content = join_string_array(map_array);
	free_array((void **) map_array);
	player_pos = ft_strchr(map->content, 'P') - map->content;
	set_additional_map_variables(map, player_pos);
	initialize_map_player(map, player_pos);
	load_spritesheets(map);
	load_map_collectibles(map);
	load_patrols(map);
	return (map);
}

void	initialize_map_player(t_map *map, size_t player_pos)
{
	map->player = ft_calloc(sizeof(t_player), 1);
	if (!map->player)
		exit_perror("malloc error");
	map->player->facing_offset = 4;
	map->player->move_direction = dir_up;
	map->player->moves_taken = 0;
	map->player->pos = player_pos;
}

void	load_spritesheets(t_map *map)
{
	map->bg_sprites = read_spritesheet("sprites/dungeon.png", 32, 15, 12);
	map->lava_sprites = read_spritesheet("sprites/lava.png", 32, 12, 18);
	map->shadow_sprites = read_spritesheet("sprites/shadows.png", 32, 5, 6);
	map->player_sprites = read_spritesheet("sprites/dragon.png", 48, 8, 7);
	map->patrol_sprites = read_spritesheet("sprites/necromancer.png", 48, 8, 5);
	map->gui_bg_sprites = read_spritesheet("sprites/paper.png", 32, 3, 3);
	map->gui_end_sprites = read_spritesheet("sprites/paper_transparent.png", \
											32, 3, 3);
	map->gui_charset = read_spritesheet("sprites/monogram.png", 32, 8, 16);
}

char	*join_string_array(char **array)
{
	char	*str;
	char	*str2;
	size_t	i;

	i = 0;
	if (!array[i])
		return (NULL);
	else
		str = ft_strdup(array[i]);
	if (!str)
		exit_perror("malloc error");
	i++;
	while (array[i])
	{
		str2 = ft_strjoin(str, array[i]);
		if (!str2)
			exit_perror("malloc error");
		free(str);
		str = str2;
		i++;
	}
	return (str);
}
