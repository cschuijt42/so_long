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

// -- DEFINES --

// The minimum width of the window in map tiles, to ensure the GUI can be
// properly drawn.
# define MIN_MAP_W 12
// Amount of pixels that the map rendering needs to be offset by to make room
// for the GUI above.
# define GUI_OFFSET 128

// Sprite height for projecting onto other images
# define SPRITE_H 32
// Sprite width for projecting onto other images
# define SPRITE_W 32

// RGBA color to render text in
# define TEXT_COLOR 0x000000FF
// Font dimensions in the spritesheet and pixel buffers
# define FONT_SPRITE_DIMS 32
// Font width for projecting letters subsequently onto other images
# define FONT_W 11

// -- ENUMS --

typedef enum e_render_layers {
	layer_bg,
	layer_bg_sprites,
	layer_shadows,
	layer_collectibles,
	layer_indicators,
	layer_patrols,
	layer_player,
	layer_pillars,
	layer_gui
}	t_render_layers;

typedef enum e_direction {
	dir_up,
	dir_right,
	dir_down,
	dir_left
}	t_direction;

// -- STRUCTS --

// @brief One sprite, instantiated from a larger spritesheet.
// 
// Sprites are a singly linked list of all background tiles loaded into
// an MLX image. By using the list, sprites that are needed more than once
// are only turned into an image once, and just reinstantiated after that.
// Setting a number of animation frames will tell the game to loop through
// a number of consecutive sprites on a clock, keeping the same image but
// repeatedly changing its pixel buffer.
//
// @param spritesheet The array of pixel buffers this sprite originated from.
// @param index       The index in spritesheet at which this sprite is located.
// @param image       The MLX image at which this sprite is instantiated.
// @param next        The next sprite, or NULL if this is the end of the list.
// @param animation_frames The amount of consecutive sprites that form an
//                         animation loop.
typedef struct s_sprite {
	uint8_t			**spritesheet;
	size_t			index;
	mlx_image_t		*image;
	int				animation_frames;
	struct s_sprite	*next;
}	t_sprite;

// @brief A floor tile spanning one or more spaces on the map.
//
// Floor tiles are a circular linked list, allowing the sprite setter to loop
// through them as much as needed to fill in all open floor spaces. The pattern
// in a floor tile is an unsigned char array of six characters, describing the
// following spaces in clockwise order:
//
//      0  1
//   4  3  2
//
// Each character's numeric value tells the game which sprite to fill in at
// that location, using position 0 as the reference point. If a character is
// set to byte value zero, that tile is not considered for fitting the tile,
// and will not be overridden when deciding to place it.
typedef struct s_floortile {
	char				*pattern;
	struct s_floortile	*next;
}	t_floortile;

// @brief A list of the collectibles on the map.
//
// Collectibles are a singly linked list describing each collectible on the map,
// including whether it's been picked up or not and which instance ID is
// responsible for rendering this particular collectible. By iterating over this
// list, the game can determine how many collectibles have been picked up and
// whether to allow the player to finish the game.
//
// @param pos       The location on the map where this collectible is at.
// @param instance  The instance ID with which this collectible is rendered.
// @param picked_up 0 if not picked up, 1 if picked up.
typedef struct s_collectible {
	size_t					pos;
	size_t					instance;
	uint8_t					picked_up;
	struct s_collectible	*next;
}	t_collectible;

// @brief A struct representing all variables to do with the player entity.
//
// @param image          The MLX image with which the player is rendered.
// @param pos            The position of the player on the map.
// @param moves_taken    Amount of moves taken by the player.
// @param move_direction A number from e_direction to indicate which way the
//                       player is moving.
// @param facing_offset  The amount by which the sprite index needs to change
// based on which way the player is facing right now. 4 for left, 0 for right.
typedef struct s_player {
	mlx_image_t		*image;
	size_t			pos;
	size_t			moves_taken;
	size_t			move_direction;
	size_t			facing_offset;
}	t_player;

// @brief Struct for a single enemy patrol.
//
// @param image          The MLX image with which this patrol is rendered.
// @param pos            The position of this patrol on the map.
// @param move_direction A number from e_direction to indicate the direction
//                       this patrol is currently moving in.
// @param facing_offset  The amount of sprites to offset rendering by,
//                       should be 0 or 4.
// @param next           The next patrol in the list, or NULL if last patrol.
typedef struct s_patrol {
	mlx_image_t		*image;
	size_t			pos;
	size_t			move_direction;
	size_t			facing_offset;
	struct s_patrol	*next;
}	t_patrol;

// @brief Struct for all game data, from the map to sprites to MLX.
//
// @param mlx               The MLX instance this map is being rendered in.
// @param map_name          Name of the map file loaded into the game.
// @param content           String containing the map as it is in the file,
//                          stripped of newlines.
// @param sprite_categories String containing letters indicating which kind of
//                          sprites need to be used for each space on the map:
//                          W = wall,              L = lava,
//                          N = front-facing wall, F = floor,
//                          P = pillar,            E = exit
// @param render_terrain    Unsigned char array of sprite indices for the
//                          background of each space on the map.
//                          sprite_categories indicates which spritesheet
//                          the index refers to.
// @param render_shadows    Unsigned char array of sprite indices for the
//                          shadows on each space of the map.
// @param background        MLX image for the background layer of the game,
//                          which should be filled with a single color. Also
//                          contains the parts of the GUI which do not need to
//                          update as the game runs.
// @param gui_moves         MLX image for the move count in the GUI. 
// @param gui_collectibles  MLX image for the currently picked up collectible
//                          count in the GUI.
// @param height            Total height of the map, in spaces.
// @param width             Total width of the map, in spaces.
// @param size              Total size of the map, in spaces.
// @param player            Struct containing all player entity information.
// @param movement_clock    Clock that counts up for each animation frame in a
//                          player move, tells those functions which frame to
//                          display next.
// @param lock_input        When not 0, tells the game to ignore inputs because
//                          an animation is playing.
// @param col_total         Total amount of collectibles on the map.
// @param col_grabbed       Amount of collectibles grabbed by the player.
// @param collectibles      Linked list of collectibles with their location and
//                          render instance.
// @param bg_sprites        Spritesheet containing the background sprites,
//                          floors, walls, etc.
// @param lava_sprites      Spritesheet containing the lava streams.
// @param shadow_sprites    Spritesheet containing the shadow sprites.
// @param player_sprites    Spritesheet containing all animation frames for the
//                          player character.
// @param patrol_sprites    Spritesheet containing all animation frames for the
//                          enemies.
// @param gui_bg_sprites    Spritesheet containing the background tiles for
//                          the GUI.
// @param gui_charset       Spritesheet containing the letters to draw onto
//                          the GUI.
// @param sprites           Linked list of instantiated background sprites to
//                          avoid creating more MLX images than required.
typedef struct s_map {
	mlx_t			*mlx;
	char			*map_name;
	char			*content;
	char			*sprite_categories;
	char			*render_terrain;
	char			*render_shadows;
	mlx_image_t		*background;
	size_t			height;
	size_t			width;
	size_t			size;
	t_player		*player;
	t_patrol		*patrols;
	int				movement_clock;
	int				lock_input;
	size_t			col_total;
	char			*col_total_str;
	size_t			col_grabbed;
	t_collectible	*collectibles;
	uint8_t			**bg_sprites;
	uint8_t			**lava_sprites;
	uint8_t			**shadow_sprites;
	uint8_t			**player_sprites;
	uint8_t			**patrol_sprites;
	uint8_t			**gui_bg_sprites;
	uint8_t			**gui_charset;
	t_sprite		*sprites;
}	t_map;

// -- MAP INITIALIZATION --

t_map		*initialize_map(char *path);
char		*read_map_from_file(int fd);
void		initialize_map_player(t_map *map, size_t player_pos);
void		fill_in_map_name(t_map *map, char *path);
void		fit_map_array_to_window(char ***map_array);
void		add_top_row(char ***map_array);
void		set_additional_map_variables(t_map *map, size_t player_pos);

// -- SPRITESHEETS --

uint8_t		**read_spritesheet(char *path, size_t dim, size_t w, size_t h);
uint8_t		*crop_buffer(uint8_t *texture, size_t i, size_t dim, size_t w);
void		load_spritesheets(t_map *map);
void		sprite_buffer_to_image(uint8_t *buffer, mlx_image_t *image, \
								size_t x, size_t y);

// -- TEXT RENDERING --

void		string_to_image(char *str, mlx_image_t *image, \
							uint8_t **charset, size_t xy[2]);
void		string_to_image_right(char *str, mlx_image_t *image, \
								uint8_t **charset, size_t xy[2]);
void		char_to_image(uint8_t *chr, mlx_image_t *image, \
							size_t xy[2], uint32_t color);

// -- MAP VALIDATIONS --

void		run_map_validations(char **map_rows, char *map_str);
void		validate_filename(char *file);
void		validate_empty_lines(char *map);
void		validate_map_measurements(char **map);
void		validate_map_boundaries(char **map);
void		validate_map_content(char *map);
void		validate_map_solvability(t_map *map);

// -- PATROLS --

void		load_patrols(t_map *map);
void		add_new_patrol(t_map *map, size_t pos, char dir);
void		add_patrol_to_map(t_map *map, t_patrol *patrol);
int			should_be_patrol(char c);
void		render_patrols(t_map *map);

// -- MAP RENDERING PASSES --

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

// -- GUI helpers --

void		render_gui(t_map *map);
void		render_gui_static_strings(t_map *map);
void		render_gui_dynamic_strings(t_map *map);

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

void		fill_in_north_wall_sprites(t_map *map);
size_t		fill_in_north_wall_segment(t_map *map, size_t i);
void		decorate_north_wall_segment(t_map *map, size_t i, size_t len);
uint8_t		undecorated_north_wall_sprite(void);

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
void		player_movement_wrapper(t_map *map, char key);
void		try_move_player_up(t_map *map);
void		try_move_player_left(t_map *map);
void		try_move_player_down(t_map *map);
void		try_move_player_right(t_map *map);

void		movement_animation_wrapper(t_map *map);
void		animate_player_movement_up(t_map *map);
void		animate_player_movement_right(t_map *map);
void		animate_player_movement_down(t_map *map);
void		animate_player_movement_left(t_map *map);

void		animate_player_hook(void *map_ptr);
void		animate_background_hook(void *map_ptr);
void		mark_sprites_for_animation(t_map *map);

int			run_gameplay_checks(t_map *map);
void		try_pick_up_collectible(t_map *map, size_t pos);
int			try_exit_map(t_map *map);
int			player_next_to_patrol(t_map *map);
int			game_over(t_map *map, int victory);

void		patrol_movement_animation_wrapper(t_map *map);
void		update_patrol_movement_direction(t_map *map, t_patrol *patrol);
void		update_patrol_facing_offset(t_patrol *patrol);
void		animate_patrol_movement_up(t_map *map, t_patrol *patrol);
void		animate_patrol_movement_right(t_map *map, t_patrol *patrol);
void		animate_patrol_movement_down(t_map *map, t_patrol *patrol);
void		animate_patrol_movement_left(t_map *map, t_patrol *patrol);
void		idle_animate_patrols(t_map *map, size_t offset);

// -- SPRITE MANAGEMENT --

t_sprite	*add_new_sprite(t_map *map, uint8_t **sheet, size_t index);
t_sprite	*find_or_create_sprite(t_map *map, uint8_t **sheet, size_t i);

// -- STRUCT FUNCTIONS -- 

t_map		*initialize_map_struct(char **map_array);
void		free_map_struct(t_map *map);
void		detach_images_from_spritesheets(t_map *map);
void		free_linked_lists(t_map *map);
void		free_map_collectibles(t_map *map);

// -- HELPERS --

char		*join_string_array(char **array);
char		*last_string_in_array(char **array);

// -- FREEING/EXIT FUNCTIONS --

void		free_array(void **array);
void		exit_message(char *msg);
void		exit_perror(char *msg);

#endif
