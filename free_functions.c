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
#include <stdlib.h>
#include <stdio.h>

// @brief Frees each element in a NULL-terminated array of pointers, then
// frees the array itself. Does not set array pointer to NULL.
void	free_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// @brief Prints "Error\n" on stderr, followed by a message, then exits the
// program with code 1.
void	exit_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

// @brief Calls perror with msg, then exits the program with code 1.
void	exit_perror(char *msg)
{
	perror(msg);
	exit(1);
}
