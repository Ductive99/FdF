/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:15:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:10:27 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	apply_terrain_colors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->points[i].color = map->terrain_colors[i];
		i++;
	}
}

void	apply_default_colors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (map->original_colors[i] != 0xFFFFFF)
			map->points[i].color = map->original_colors[i];
		else
			map->points[i].color = get_earth_color((int)map->points[i].z);
		i++;
	}
}
