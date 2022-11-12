/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 20:32:15 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/12 20:32:15 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split_array(char ***array)
{
	size_t	i;

	i = 0;
	while (*array[i])
	{
		free(*array[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
