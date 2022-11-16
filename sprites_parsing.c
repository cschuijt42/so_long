/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_parsing.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 21:33:09 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/15 21:33:09 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

// @brief Takes a spritesheet and returns an array of pixel buffers for each
// sprite, sorted left to right and top to bottom.
// @param path The path to the png file containing the spritesheet.
// @param dim The dimensions of each sprite, eg. 16 for a sheet of 16x16
// sprites.
// @param w The amount of sprites per row of the sheet.
// @param h The amount of sprites per column of the sheet.
// @return A NULL-terminated array of pointers to each pixel buffer, which
// can each be dropped into images at will.
uint8_t	**read_spritesheet(char *path, size_t dim, size_t w, size_t h)
{
	size_t			i;
	uint8_t			**array;
	mlx_texture_t	*texture;

	i = 0;
	texture = mlx_load_png(path);
	if (!texture)
		exit_perror("texture loading error");
	array = malloc(sizeof(uint8_t *) * ((w * h) + 1));
	if (!array)
		exit_perror("malloc error");
	while (i < w * h)
	{
		array[i] = crop_buffer(texture->pixels, i, dim, w);
		i++;
	}
	array[i] = NULL;
	return (array);
}

// @brief Returns a pixel buffer for the given sprite in a sprite sheet.
// skips ahead to sprite i, by determining how many rows we've been through
// using w, then uses ft_memmove on it, one row at a time.
// @param texture Pointer to the texture's pixel buffer.
// @param i       Index of the sprite being cropped.
// @param dim     Dimensions of the sprite (eg. 16 for a 16x16 sprite)
// @param w       Amount of sprites in a row of the spritesheet.
uint8_t	*crop_buffer(uint8_t *texture, size_t i, size_t dim, size_t w)
{
	size_t		pos;
	size_t		y;
	uint8_t		*buffer;

	pos = 0 + ((i / w) * dim * dim * w * 4);
	pos += (i % w) * dim * 4;
	buffer = malloc(sizeof(uint8_t) * dim * dim * 4);
	if (!buffer)
		exit_perror("malloc error");
	y = 0;
	while (y < dim)
	{
		ft_memmove(&buffer[y * dim * 4], &texture[pos], dim * 4);
		pos += dim * w * 4;
		y++;
	}
	return (buffer);
}
