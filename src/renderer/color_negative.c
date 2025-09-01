/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:56:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/28 12:23:51 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_negative_terrain_color(int z_value, float abs_min_z)
{
	float	t;

	t = (float)(-z_value) / abs_min_z;
	return (get_color(t, 0x2161d2, 0x000000));
}
