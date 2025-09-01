/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:06:42 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cleanup_projected_points(t_projected_data *proj_data)
{
	if (proj_data->points)
	{
		free(proj_data->points);
		proj_data->points = NULL;
		proj_data->last_map_size = 0;
	}
}

t_point	*get_projected_points(t_map *map, t_projected_data *proj_data)
{
	int	current_map_size;

	current_map_size = map->width * map->height;
	if (current_map_size != proj_data->last_map_size)
	{
		if (proj_data->points)
			free(proj_data->points);
		proj_data->points = malloc(current_map_size * sizeof(t_point));
		if (!proj_data->points)
			return (NULL);
		proj_data->last_map_size = current_map_size;
	}
	return (proj_data->points);
}

int	calculate_lod_step(int map_size, float zoom)
{
	if (map_size > 100000 && zoom < 0.5)
		return (4);
	else if (map_size > 50000 && zoom < 0.8)
		return (2);
	return (1);
}

void	project_all_points(t_point *proj_pts, t_map *map, t_view *view)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = map->width * map->height;
	while (i < map_size)
	{
		proj_pts[i] = map->points[i];
		project_pt(&proj_pts[i], map, view);
		i++;
	}
}

void	cleanup_wireframe_utils(t_projected_data *proj_data)
{
	cleanup_projected_points(proj_data);
}
