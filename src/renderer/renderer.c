/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:15:16 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 15:08:59 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	calculate_scale_factor(t_map *map)
{
	float	map_diagonal;
	float	scale_x;
	float	scale_y;

	map_diagonal = sqrt(map->width * map->width + map->height * map->height);
	scale_x = WINDOW_WIDTH * 0.8 / map_diagonal;
	scale_y = WINDOW_HEIGHT * 0.8 / map_diagonal;
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}
