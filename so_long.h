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

typedef struct s_floortile {
	char				*pattern;
	struct s_floortile	*next;
}	t_floortile;

typedef struct s_collectible {
	size_t					pos;
	size_t					instance;
	uint8_t					picked_up;
	struct s_collectible	*next;
}	t_collectible;

typedef struct s_player {
	mlx_image_t		*image;
	size_t			pos;
	size_t			moves_taken;
}	t_player;

typedef struct s_map {
	mlx_t			*mlx;
	char			*content;
	char			*sprite_categories;
	char			*render_terrain;
	char			*render_shadows;
	mlx_image_t		*background_fill;
	size_t			height;
	size_t			width;
	size_t			size;
	t_player		*player;
	int				animation_cycle;
	int				lock_input;
	size_t			player_pos;
	size_t			total_collectibles;
	size_t			collected_collectibles;
	t_collectible	*collectibles;
	uint8_t			**wall_sprites;
	uint8_t			**lava_sprites;
	uint8_t			**shadow_sprites;
	uint8_t			**player_sprites;
	uint8_t			**patrol_sprites;
	t_sprite		*sprites;
}	t_map;

// -- MAP INITIALIZATION --

t_map		*initialize_map(char *path);
char		*read_map_from_file(int fd);
void		initialize_map_player(t_map *map);

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
// Render layers:
// 6: HUD
// 5: top half of pillars
// 4: player and other entities
// 3: collectibles
// 2: shadows
// 1: walls, lava, floors, bottom half of pillars
// 0: one image filled with pixels of the background color

void		categorize_map_walls(t_map *map);
void		fill_in_background_sprite_indexes(t_map *map);
void		render_map(t_map *map);
void		render_background_sprite(t_map *map, size_t i, uint8_t **sprites);
void		render_pillar(t_map *map, size_t i);
void		render_background_pixels(t_map *map);
void		render_collectibles(t_map *map);
void		render_shadows(t_map *map);
void		render_shadow_sprite(t_map *map, size_t i);
void		render_player(t_map *map);

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

// -- Shadow pass helpers --

void		determine_shadow_sprites(t_map *map);
void		fill_in_floor_shadow(t_map *map, size_t i);
int			should_have_shadow(t_map *map, size_t i);
int			is_wall(t_map *map, size_t i);
int			is_floor_or_lava(t_map *map, size_t i);

void		corner_floor_shadow(t_map *map, size_t i);
void		small_corner_floor_shadow(t_map *map, size_t i);
void		continuous_n_floor_shadow(t_map *map, size_t i);
void		ending_n_floor_shadow(t_map *map, size_t i);
void		continuous_w_floor_shadow(t_map *map, size_t i);
void		ending_w_floor_shadow(t_map *map, size_t i);

// -- Exit helpers --

uint8_t		determine_exit_sprite(t_map *map, size_t i);

// -- COLLECTIBLES --

void		load_map_collectibles(t_map *map);
void		add_collectible_to_map(t_map *map, size_t i);
void		clear_collectible_list(t_map *map);

// -- RENDER TOOLS --

size_t		render_x_pos(t_map *map, size_t i);
size_t		render_y_pos(t_map *map, size_t i);

// -- GAMEPLAY AND ANIMATIONS --

void		key_hook(void *map_ptr);
void		movement_wrapper(t_map *map, char key);
void		try_move_player_up(t_map *map);
void		try_move_player_left(t_map *map);
void		try_move_player_down(t_map *map);
void		try_move_player_right(t_map *map);

void		animate_player_hook(void *param);

void		try_pick_up_collectible(t_map *map, size_t pos);
void		try_exit_map(t_map *map);

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
