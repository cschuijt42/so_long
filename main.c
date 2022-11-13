/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:28:55 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/11 14:28:55 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	// t_map	*map;

	if (ac != 2)
		exit_message("please provide just the map file as a single argument");
	/* map = */initialize_map(av[1]);	
	ft_printf("Map seems good to me!\n");
	exit(0);
	return (0);
}
