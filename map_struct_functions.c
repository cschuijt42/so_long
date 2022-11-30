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
	size_t	x;
	size_t	y;

	x = ft_strlen(map_array[0]);
	y = 0;
	while (map_array[y])
		y++;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit_perror("malloc error");
	map->height = y;
	map->width = x;
	map->content = join_string_array(map_array);
	map->size = ft_strlen(map->content);
	map->player_pos = ft_strchr(map->content, 'P') - map->content;
	map->content[map->player_pos] = '0';
	map->total_collectibles = ft_strchrc(map->content, 'C');
	load_spritesheets(map);
	load_map_collectibles(map);
	return (map);
}

void	load_spritesheets(t_map *map)
{
	map->wall_sprites = read_spritesheet("sprites/dungeon.png", 32, 15, 12);
	map->lava_sprites = read_spritesheet("sprites/lava.png", 32, 12, 18);
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

void	free_map_struct(t_map *map)
{
	free(map->content);
	free(map->sprite_categories);
	free(map->render_terrain);
	free(map->render_shadows);
	free_array((void **) map->wall_sprites);
	free_array((void **) map->lava_sprites);
	free_array((void **) map->shadow_sprites);
	free_array((void **) map->character_sprites);
	free(map);
}
