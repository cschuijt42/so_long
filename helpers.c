/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 21:26:40 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/12 21:26:40 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*last_string_in_array(char **array)
{
	size_t	i;

	i = 0;
	if (!array[i])
		return (NULL);
	while (array[i])
		i++;
	i--;
	return (array[i]);
}
