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
# include "mlx42/include/MLX42/MLX42.h"

// -- STRUCTS --

typedef struct s_sprite {
	uint8_t			**spritesheet;
	size_t			index;
	mlx_image_t		*image;
	struct s_sprite	*next;
}	t_sprite;

typedef struct s_map {
	mlx_t		*mlx;
	char		*content;
	char		*sprite_categories;
	char		*render_terrain;
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

typedef struct s_floortile {
	char				*pattern;
	struct s_floortile	*next;
}	t_floortile;

// -- MAP INITIALIZATION --

t_map		*initialize_map(char *path);
char		*read_map_from_file(int fd);

// -- SPRITESHEETS --

uint8_t		**read_spritesheet(char *path, size_t dim, size_t w, size_t h);
uint8_t		*crop_buffer(uint8_t *texture, size_t i, size_t dim, size_t w);
void		load_spritesheets(t_map *map);

// -- MAP VALIDATIONS --

void		validate_filename(char *file);
void		validate_empty_lines(char *map);
void		validate_map_measurements(char **map);
void		validate_map_boundaries(char **map);
void		validate_map_content(char *map);
void		validate_map_solvability(t_map *map);

// -- MAP RENDERING PASSES --

void		categorize_map_walls(t_map *map);
void		fill_in_background_sprite_indexes(t_map *map);
void		render_map(t_map *map);
void		render_background_sprite(t_map *map, size_t i, uint8_t **sprites);

// -- Categorization helpers --

void		initial_wall_seed(t_map *map);
void		recursive_walls(t_map *map);
int			neighbors_wall(t_map *map, size_t i);
int			can_be_wall(t_map *map, size_t i);
void		lava_and_pillars(t_map *map);
void		north_walls(t_map *map);
void		fill_floors_and_strip_walls(t_map *map);
int			is_edge_wall(size_t i, t_map *map);
int			floor_or_north_wall(size_t i, t_map *map);

// -- Wall pass helpers --

uint8_t		determine_wall_sprite(t_map *map, size_t i);
int			check_against_bitmask(uint8_t input, char *mask, int c);
uint8_t		cyclical_shift_two(uint8_t in);

uint8_t		edge_single(uint8_t surroundings);
uint8_t		edge_consecutive(uint8_t surroundings);
uint8_t		edge_opposing(uint8_t surroundings);
uint8_t		edge_triple(uint8_t surroundings);

uint8_t		wall_corner(uint8_t surroundings);
uint8_t		wall_single(uint8_t surroundings);
uint8_t		wall_opposing(uint8_t surroundings);
uint8_t		wall_triple(uint8_t surroundings);
uint8_t		wall_corner_edge(uint8_t surroundings);

uint8_t		wall_single_edge_lr(uint8_t surroundings);
uint8_t		wall_single_edge_l(uint8_t surroundings);
uint8_t		wall_single_edge_r(uint8_t surroundings);

// -- Lava pass helpers --

uint8_t		determine_lava_sprite(t_map *map, size_t i);
uint8_t		match_high_lava_sprites(uint8_t surroundings);
uint8_t		match_low_lava_sprites(uint8_t surroundings);

// -- Floor pass helpers --

void		fill_in_floors(t_map *map);
uint8_t		determine_floor_surroundings(t_map *map, size_t i);
int			floor_tile_fits_space(uint8_t surroundings, char *tile);
void		fill_in_floor_tile(t_map *map, size_t i, char *tile);

t_floortile	*initialize_tile_list(void);
t_floortile	*add_tile_to_list(t_floortile **list, char *pattern);
t_floortile	*new_tile(char *pattern);
void		free_tile_list(t_floortile **list);

// -- RENDER TOOLS --

size_t		render_x_pos(t_map *map, size_t i);
size_t		render_y_pos(t_map *map, size_t i);

// -- SPRITE MANAGEMENT --

t_sprite	*add_new_sprite(t_map *map, uint8_t **sheet, size_t index);
t_sprite	*find_or_create_sprite(t_map *map, uint8_t **sheet, size_t i);

// -- STRUCT FUNCTIONS -- 

t_map		*initialize_map_struct(char **map_array);
void		free_map_struct(t_map *map);

// -- HELPERS --

char		*join_string_array(char **array);
char		*last_string_in_array(char **array);

// -- FREEING/EXIT FUNCTIONS --

void		free_array(void **array);
void		exit_message(char *msg);
void		exit_perror(char *msg);

#endif
