/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrols.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 21:16:20 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/27 21:16:20 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef BONUS

void	load_patrols(t_map *map)
{
	(void) map;
	return ;
}

#else

void	load_patrols(t_map *map)
{
	(void) map;
	ft_printf("Bonus activated, but there's no patrol code yet!");
}

#endif