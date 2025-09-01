/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_wireframe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:40:52 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <time.h>

static int	process_water_flow_step(t_vars *vars, int step)
{
	int	row;
	int	col;
	int	idx;
	int	progress_made;
	int	force_spread;

	progress_made = 0;
	force_spread = (step > 3 && step % 5 == 0);
	row = -1;
	while (++row < vars->map->height)
	{
		col = -1;
		while (++col < vars->map->width)
		{
			idx = row * vars->map->width + col;
			if (vars->flow_map[idx] == step)
			{
				spread_basic_directions(vars, row, col, step + 1);
				if (rand() % 100 < 35 || force_spread)
					spread_diagonal_directions(vars, row, col, step + 1);
				progress_made = 1;
			}
		}
	}
	return (progress_made);
}

void	advance_water_flow(t_vars *vars, int current_step)
{
	int	progress_made;
	int	row;
	int	col;

	progress_made = process_water_flow_step(vars, current_step);
	if (!progress_made && current_step < vars->map->width * vars->map->height
		/ 4)
	{
		row = rand() % vars->map->height;
		col = rand() % vars->map->width;
		if (vars->flow_map[row * vars->map->width + col] == -1)
			vars->flow_map[row * vars->map->width + col] = current_step + 1;
	}
}

static void	draw_water_lines(t_vars *vars, t_point *proj_pts, int row, int col)
{
	if (col < vars->map->width - 1 && is_point_flooded(row, col + 1, vars,
			vars->view.animation_step))
		draw_line(&vars->img, proj_pts[row * vars->map->width + col],
			proj_pts[row * vars->map->width + col + 1]);
	if (row < vars->map->height - 1 && is_point_flooded(row + 1, col, vars,
			vars->view.animation_step))
		draw_line(&vars->img, proj_pts[row * vars->map->width + col],
			proj_pts[(row + 1) * vars->map->width + col]);
}

void	draw_animated_wireframe(t_vars *vars)
{
	t_point	*proj_pts;
	int		row;
	int		col;

	advance_water_flow(vars, vars->view.animation_step);
	proj_pts = get_projected_points(vars->map, &vars->proj_data);
	if (!proj_pts)
		return ;
	project_all_points(proj_pts, vars->map, &vars->view);
	row = 0;
	while (row < vars->map->height)
	{
		col = 0;
		while (col < vars->map->width)
		{
			if (is_point_flooded(row, col, vars, vars->view.animation_step))
				draw_water_lines(vars, proj_pts, row, col);
			col++;
		}
		row++;
	}
}
