/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:30:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:06:42 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/parser.h"

void	init_view(t_view *view)
{
	view->projection = 0;
	view->zoom = 1.0;
	view->z_scale = 1.0;
	view->offset_x = 0;
	view->offset_y = 0;
	view->x_angle = 0.0;
	view->y_angle = 0.0;
	view->z_angle = 0.0;
	view->color_scheme = 0;
	view->animate_mode = 0;
	view->animation_step = 0;
	view->max_steps = 0;
}

void	init_projected_data(t_projected_data *proj_data)
{
	proj_data->points = NULL;
	proj_data->last_map_size = 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
