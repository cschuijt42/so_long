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
						uint8_t **charset, size_t xy[2])
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			char_to_image(charset[(int)(str[i])], image, xy, TEXT_COLOR);
		else
			char_to_image(charset['?'], image, xy, TEXT_COLOR);
		xy[0] += FONT_W;
		i++;
	}
}

void	string_to_image_right(char *str, mlx_image_t *image, \
							uint8_t **charset, size_t xy[2])
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 1;
	while (i <= len)
	{
		if (ft_isprint(str[len - i]))
			char_to_image(charset[(int)(str[len - i])], image, xy, TEXT_COLOR);
		else
			char_to_image(charset['?'], image, xy, TEXT_COLOR);
		xy[0] -= FONT_W;
		i++;
	}
}

void	char_to_image(uint8_t *chr, mlx_image_t *image, \
						size_t xy[2], uint32_t color)
{
	size_t		i;
	uint32_t	*src;

	i = 0;
	src = (uint32_t *) chr;
	while (i < FONT_SPRITE_DIMS * FONT_SPRITE_DIMS)
	{
		if (src[i] == 0xFFFFFFFF)
			mlx_put_pixel(image, xy[0] + (i % FONT_SPRITE_DIMS), \
							xy[1] + (i / FONT_SPRITE_DIMS), color);
		i++;
	}
}
