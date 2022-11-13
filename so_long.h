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

// -- STRUCTS --

typedef struct s_map {
	char	*content;
	size_t	rows;
	size_t	row_length;
}	t_map;

// -- MAP INITIALIZATION --

t_map	*initialize_map(char *path);
char	*read_map_from_file(int fd);

// -- VALIDATIONS --

void	validate_filename(char *file);
void	validate_map_measurements(char **map);
void	validate_map_boundaries(char **map);
void	validate_map_content(char *map);
void	validate_map_solvability(t_map *map);

// -- STRUCT FUNCTIONS -- 

t_map	*initialize_map_struct(char **map_array);
void	free_map_struct(t_map *map);

// -- HELPERS --

char	*join_string_array(char **array);
char	*last_string_in_array(char **array);

// -- FREEING FUNCTIONS --

void	free_split_array(char **array);

#endif
