/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:32:03 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/11 14:32:03 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// -- INCLUDES --

# include "libft/libft.h"
# include "include/MLX42.h"

// -- STRUCTS --

typedef struct s_map {
	mlx_t		*mlx;
	char		*content;
	char		*render_categories;
	char		*render_walls;
	char		*render_lava;
	char		*render_floor;
	char		*render_shadows;
	size_t		height;
	size_t		width;
	size_t		size;
	size_t		player_pos;
	size_t		total_collectibles;
	size_t		collectibles;
	uint8_t		**wall_sprites;
	uint8_t		**lava_sprites;
	uint8_t		**shadow_sprites;
	uint8_t		**character_sprites;
	t_sprite	*sprites;
}	t_map;

typedef struct s_sprite {
	uint8_t			**spritesheet;
	size_t			index;
	mlx_image_t		*image;
	struct s_sprite	*next;
}	t_sprite;

// -- MAP INITIALIZATION --

t_map	*initialize_map(char *path);
char	*read_map_from_file(int fd);

// -- SPRITESHEETS --

uint8_t	**read_spritesheet(char *path, size_t dim, size_t w, size_t h);
uint8_t	*crop_buffer(uint8_t *texture, size_t i, size_t dim, size_t w);

// -- MAP VALIDATIONS --

void	validate_filename(char *file);
void	validate_empty_lines(char *map);
void	validate_map_measurements(char **map);
void	validate_map_boundaries(char **map);
void	validate_map_content(char *map);
void	validate_map_solvability(t_map *map);

// -- MAP RENDERING PASSES --

void	categorize_map_walls(t_map *map);
void	fill_in_wall_map(t_map *map);
void	render_map(t_map *map);

// -- Categorization helpers --

void	initial_wall_seed(t_map *map);
void	recursive_walls(t_map *map);
int		neighbors_wall(t_map *map, size_t i);
int		can_be_wall(t_map *map, size_t i);
void	lava_and_pillars(t_map *map);
void	north_walls(t_map *map);
void	fill_floors_and_strip_walls(t_map *map);
int		is_edge_wall(size_t i, t_map *map);
int		floor_or_north_wall(size_t i, t_map *map);

// -- Wall pass helpers --

uint8_t	determine_wall_sprite(t_map *map, size_t i);
int		check_against_bitmask(uint8_t in, char *mask, int c);
uint8_t	cyclical_shift_two(uint8_t in);

uint8_t	edge_single(uint8_t surroundings);
uint8_t	edge_consecutive(uint8_t surroundings);
uint8_t	edge_opposing(uint8_t surroundings);
uint8_t	edge_triple(uint8_t surroundings);

uint8_t	wall_corner(uint8_t surroundings);
uint8_t	wall_single(uint8_t surroundings);
uint8_t	wall_opposing(uint8_t surroundings);
uint8_t	wall_triple(uint8_t surroundings);
uint8_t	wall_corner_edge(uint8_t surroundings);

uint8_t	wall_single_edge_lr(uint8_t surroundings);
uint8_t	wall_single_edge_l(uint8_t surroundings);
uint8_t	wall_single_edge_r(uint8_t surroundings);

// -- STRUCT FUNCTIONS -- 

t_map	*initialize_map_struct(char **map_array);
void	free_map_struct(t_map *map);

// -- HELPERS --

char	*join_string_array(char **array);
char	*last_string_in_array(char **array);

// -- FREEING/EXIT FUNCTIONS --

void	free_array(void **array);
void	exit_message(char *msg);
void	exit_perror(char *msg);

#endif
