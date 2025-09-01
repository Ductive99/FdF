/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:14:02 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:23:35 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

/**
 * Loop through each line
 * atoi each number - save x, y, z values
 *  check hex color and calculate it
 */

t_point	*fill_map(char *filepath, t_map *map)
{
	if (!allocate_map_arrays(map))
		return (NULL);
	if (!read_map_data(filepath, map))
		return (NULL);
	set_points(map);
	return (map->points);
}

void	set_points(t_map *map)
{
	int	total_points;
	int	i;

	i = 0;
	map->min_z = map->points[0].z;
	map->max_z = map->points[0].z;
	total_points = map->width * map->height;
	while (i < total_points)
	{
		if (map->points[i].z < map->min_z)
			map->min_z = map->points[i].z;
		if (map->points[i].z > map->max_z)
			map->max_z = map->points[i].z;
		i++;
	}
	precompute_terrain_colors(map);
}

void	get_coordinates(t_map *map, char *line, int row)
{
	char	**tokens;
	int		col;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return ;
	col = -1;
	while (tokens[++col] && col < map->width)
		process_token(map, tokens[col], row, col);
	free_tokens(tokens);
}
