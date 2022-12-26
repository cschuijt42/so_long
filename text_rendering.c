/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_rendering.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/26 19:02:50 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/26 19:02:50 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	string_to_image(char *str, mlx_image_t *image, \
						uint8_t **charset, uint32_t color)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			char_to_image(charset[(int)(str[i])], image, (i * FONT_W), color);
		else
			char_to_image(charset['?'], image, (i * FONT_W), color);
		i++;
	}
}

void	char_to_image(uint8_t *chr, mlx_image_t *image, \
						size_t x, uint32_t color)
{
	size_t		i;
	uint32_t	*src;

	i = 0;
	src = (uint32_t *) chr;
	while (i < FONT_SPRITE_DIMS * FONT_SPRITE_DIMS)
	{
		if (src[i] == 0xFFFFFFFF)
			mlx_put_pixel(image, x + (i % FONT_SPRITE_DIMS), \
							i / FONT_SPRITE_DIMS, color);
		i++;
	}
}
