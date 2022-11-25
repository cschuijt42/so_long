/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmask_helpers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 14:02:42 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/22 14:02:42 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_against_bitmask(uint8_t input, char *mask, int c)
{
	size_t		i;
	uint8_t		orig;
	uint8_t		match;

	i = 0;
	match = 0;
	orig = input;
	while (mask[i])
	{
		if (mask[i] == '1')
			match |= 1 << i;
		if (mask[i] == '*')
			input &= ~(1 << i);
		i++;
	}
	if (input == match)
		return (1);
	c--;
	if (c > 0)
		return (check_against_bitmask(cyclical_shift_two(orig), mask, c));
	return (0);
}

uint8_t	cyclical_shift_two(uint8_t in)
{
	uint8_t	swap;

	swap = (in >> 6);
	in <<= 2;
	in += swap;
	return (in);
}
