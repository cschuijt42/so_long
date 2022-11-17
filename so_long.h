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

// -- DEFINES --

# ifndef TILE_S
#  define TILE_S 16
# endif

# ifndef TILE_M
#  define TILE_M 1
# endif

// -- INCLUDES --

# include "libft/libft.h"
# include "include/MLX42.h"

// -- STRUCTS --

typedef struct s_map {
	char	*content;
	size_t	height;
	size_t	width;
}	t_map;



// -- MAP INITIALIZATION --

t_map		*initialize_map(char *path);
char		*read_map_from_file(int fd);

// -- SPRITESHEETS --

uint8_t		**read_spritesheet(char *path, size_t dim, size_t w, size_t h);
uint8_t		*crop_buffer(uint8_t *texture, size_t i, size_t dim, size_t w);

// -- MAP VALIDATIONS --

void		validate_filename(char *file);
void		validate_map_measurements(char **map);
void		validate_map_boundaries(char **map);
void		validate_map_content(char *map);
void		validate_map_solvability(t_map *map);

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
