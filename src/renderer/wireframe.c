/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:27:00 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_lines(t_data *img, t_point *pts, t_map *map, int step)
{
	int	x;
	int	y;
	int	current;
	int	right;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - step)
		{
			if (y % step == 0 && x % step == 0)
			{
				current = y * map->width + x;
				right = y * map->width + (x + step);
				draw_line(img, pts[current], pts[right]);
			}
			x += step;
		}
		y += step;
	}
}

void	draw_vertical_lines(t_data *img, t_point *pts, t_map *map, int step)
{
	int	x;
	int	y;
	int	current;
	int	bottom;

	y = 0;
	while (y < map->height - step)
	{
		x = 0;
		while (x < map->width)
		{
			if (y % step == 0 && x % step == 0)
			{
				current = y * map->width + x;
				bottom = (y + step) * map->width + x;
				draw_line(img, pts[current], pts[bottom]);
			}
			x += step;
		}
		y += step;
	}
}

void	draw_wireframe(t_vars *vars)
{
	t_point	*projected_points;
	int		step;
	int		map_size;

	if (!vars || !vars->map)
	{
		cleanup_wireframe_utils(&vars->proj_data);
		return ;
	}
	projected_points = get_projected_points(vars->map, &vars->proj_data);
	if (!projected_points)
		return ;
	map_size = vars->map->width * vars->map->height;
	step = calculate_lod_step(map_size, vars->view.zoom);
	project_all_points(projected_points, vars->map, &vars->view);
	draw_horizontal_lines(&vars->img, projected_points, vars->map, step);
	draw_vertical_lines(&vars->img, projected_points, vars->map, step);
}
