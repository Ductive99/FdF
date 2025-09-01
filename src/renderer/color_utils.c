/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:55:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/28 12:23:51 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_color(float t, uint32_t color_a, uint32_t color_b)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (1 - t) * ((color_a >> 16) & 0xFF) + t * ((color_b >> 16) & 0xFF);
	g = (1 - t) * ((color_a >> 8) & 0xFF) + t * ((color_b >> 8) & 0xFF);
	b = (1 - t) * ((color_a) & 0xFF) + t * ((color_b) & 0xFF);
	return ((r << 16) | (g << 8) | b);
}
