/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_positive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:57:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/28 12:23:51 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_positive_terrain_color(int z_value, float max_z)
{
	float	t;

	if (z_value >= 0 && z_value <= max_z / 9)
	{
		t = (float)z_value / (max_z / 9);
		return (get_color(t, 0xe8c86a, 0x329b0d));
	}
	else if (z_value > max_z / 9 && z_value <= max_z / 3)
	{
		t = (float)(z_value - max_z / 9) / (max_z / 3 - max_z / 9);
		return (get_color(t, 0x329b0d, 0x59732c));
	}
	else if (z_value > max_z / 3 && z_value <= max_z / 1.6)
	{
		t = (float)(z_value - max_z / 3) / (max_z / 1.6 - max_z / 3);
		return (get_color(t, 0x59732c, 0x674f16));
	}
	else
	{
		t = (float)(z_value - max_z / 1.6) / (max_z - max_z / 1.6);
		return (get_color(t, 0x674f16, 0xcfcdc8));
	}
}
