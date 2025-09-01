/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 15:08:59 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	update_trig_cache(t_view *view, float *cos_vals, float *sin_vals)
{
	static float	cached_angles[3] = {-999.0, -999.0, -999.0};

	if (view->x_angle != cached_angles[0])
	{
		cached_angles[0] = view->x_angle;
		cos_vals[0] = cos(view->x_angle);
		sin_vals[0] = sin(view->x_angle);
	}
	if (view->y_angle != cached_angles[1])
	{
		cached_angles[1] = view->y_angle;
		cos_vals[1] = cos(view->y_angle);
		sin_vals[1] = sin(view->y_angle);
	}
	if (view->z_angle != cached_angles[2])
	{
		cached_angles[2] = view->z_angle;
		cos_vals[2] = cos(view->z_angle);
		sin_vals[2] = sin(view->z_angle);
	}
}

static void	apply_rotations(float *coords, t_view *view, float *cos_vals,
		float *sin_vals)
{
	float	temp;

	if (view->x_angle != 0.0)
	{
		temp = coords[1] * cos_vals[0] - coords[2] * sin_vals[0];
		coords[2] = coords[1] * sin_vals[0] + coords[2] * cos_vals[0];
		coords[1] = temp;
	}
	if (view->y_angle != 0.0)
	{
		temp = coords[0] * cos_vals[1] + coords[2] * sin_vals[1];
		coords[2] = -coords[0] * sin_vals[1] + coords[2] * cos_vals[1];
		coords[0] = temp;
	}
	if (view->z_angle != 0.0)
	{
		temp = coords[0] * cos_vals[2] - coords[1] * sin_vals[2];
		coords[1] = coords[0] * sin_vals[2] + coords[1] * cos_vals[2];
		coords[0] = temp;
	}
}

static void	apply_projection(float *coords, t_view *view, int *screen_pos)
{
	float	perspective_factor;

	if (view->projection == 0)
	{
		screen_pos[0] = (int)((coords[0] - coords[1]) * 0.866025404f);
		screen_pos[1] = (int)((-coords[2] + coords[1] + coords[0]) * 0.5f);
	}
	else if (view->projection == 1)
	{
		screen_pos[0] = (int)coords[0];
		screen_pos[1] = (int)coords[1];
	}
	else if (view->projection == 2)
	{
		perspective_factor = 1000.0f / (1000.0f + coords[2]);
		screen_pos[0] = (int)(coords[0] * perspective_factor);
		screen_pos[1] = (int)(coords[1] * perspective_factor);
	}
}

t_point	project_pt(t_point *pt, t_map *map, t_view *view)
{
	float	scale;
	float	coords[3];
	float	cos_vals[3];
	float	sin_vals[3];
	int		screen_pos[2];

	scale = calculate_scale_factor(map) * view->zoom;
	coords[0] = (pt->x - (map->width / 2.0)) * scale;
	coords[1] = (pt->y - (map->height / 2.0)) * scale;
	coords[2] = pt->z * scale * view->z_scale;
	update_trig_cache(view, cos_vals, sin_vals);
	apply_rotations(coords, view, cos_vals, sin_vals);
	apply_projection(coords, view, screen_pos);
	pt->x = screen_pos[0] + (WINDOW_WIDTH / 2) + view->offset_x;
	pt->y = screen_pos[1] + (WINDOW_HEIGHT / 2) + view->offset_y;
	return (*pt);
}
