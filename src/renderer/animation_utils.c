/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:06:42 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <time.h>

typedef struct s_neighbor_data
{
	int		from_row;
	int		from_col;
	int		to_row;
	int		to_col;
	int		step;
}			t_neighbor_data;

static void	spread_water_to_neighbor(t_vars *vars, t_neighbor_data *data)
{
	int	from_idx;
	int	to_idx;
	int	height_diff;
	int	random_factor;

	if (data->to_row < 0 || data->to_row >= vars->map->height
		|| data->to_col < 0 || data->to_col >= vars->map->width)
		return ;
	to_idx = data->to_row * vars->map->width + data->to_col;
	if (vars->flow_map[to_idx] != -1)
		return ;
	from_idx = data->from_row * vars->map->width + data->from_col;
	height_diff = (int)vars->map->points[from_idx].z
		- (int)vars->map->points[to_idx].z;
	random_factor = rand() % 100;
	if (height_diff > 0 && random_factor < 90)
		vars->flow_map[to_idx] = data->step;
	else if (height_diff == 0 && random_factor < 70)
		vars->flow_map[to_idx] = data->step;
	else if (height_diff < 0 && random_factor < 40)
		vars->flow_map[to_idx] = data->step;
	else if (random_factor < 20)
		vars->flow_map[to_idx] = data->step;
}

void	spread_basic_directions(t_vars *vars, int row, int col, int step)
{
	t_neighbor_data	data;

	data.from_row = row;
	data.from_col = col;
	data.step = step;
	data.to_row = row - 1;
	data.to_col = col;
	spread_water_to_neighbor(vars, &data);
	data.to_row = row + 1;
	spread_water_to_neighbor(vars, &data);
	data.to_row = row;
	data.to_col = col - 1;
	spread_water_to_neighbor(vars, &data);
	data.to_col = col + 1;
	spread_water_to_neighbor(vars, &data);
}

void	spread_diagonal_directions(t_vars *vars, int row, int col, int step)
{
	t_neighbor_data	data;

	data.from_row = row;
	data.from_col = col;
	data.step = step;
	data.to_row = row - 1;
	data.to_col = col - 1;
	spread_water_to_neighbor(vars, &data);
	data.to_col = col + 1;
	spread_water_to_neighbor(vars, &data);
	data.to_row = row + 1;
	data.to_col = col - 1;
	spread_water_to_neighbor(vars, &data);
	data.to_col = col + 1;
	spread_water_to_neighbor(vars, &data);
}

void	init_animation(t_vars *vars)
{
	int	total_points;
	int	i;

	total_points = vars->map->width * vars->map->height;
	if (vars->flow_map)
		free(vars->flow_map);
	vars->flow_map = malloc(total_points * sizeof(int));
	if (!vars->flow_map)
		return ;
	vars->flow_map_size = total_points;
	i = 0;
	while (i < total_points)
	{
		vars->flow_map[i] = -1;
		i++;
	}
	srand(time(NULL));
	vars->flow_map[(vars->map->height / 2) * vars->map->width
		+ (vars->map->width / 2)] = 0;
	vars->view.animate_mode = 1;
	vars->view.animation_step = 0;
	vars->view.max_steps = total_points / 4;
}

int	is_point_flooded(int row, int col, t_vars *vars, int current_step)
{
	int	idx;

	if (row < 0 || row >= vars->map->height || col < 0
		|| col >= vars->map->width)
		return (0);
	idx = row * vars->map->width + col;
	if (vars->flow_map[idx] != -1 && vars->flow_map[idx] <= current_step)
		return (1);
	return (0);
}
