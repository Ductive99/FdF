/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/28 12:23:51 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_terrain_color(int z_value, t_map *map)
{
	float	max_z;
	float	min_z;
	float	abs_min_z;

	max_z = (float)map->max_z;
	min_z = (float)map->min_z;
	if (min_z < 0)
		abs_min_z = -min_z;
	else
		abs_min_z = min_z;
	if (z_value < 0)
		return (get_negative_terrain_color(z_value, abs_min_z));
	else
		return (get_positive_terrain_color(z_value, max_z));
}

uint32_t	get_earth_color(int z_value)
{
	(void)z_value;
	return (0xFFFFFF);
}

void	precompute_terrain_colors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->terrain_colors[i] = get_terrain_color((int)map->points[i].z, map);
		i++;
	}
}
