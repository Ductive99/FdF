/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:27:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:23:35 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

void	process_token(t_map *map, char *token, int row, int col)
{
	int		index;
	char	*comma;

	index = row * map->width + col;
	map->points[index].x = col;
	map->points[index].y = row;
	map->points[index].z = ft_atoi(token);
	map->points[index].color = 0xFFFFFF;
	map->original_colors[index] = 0xFFFFFF;
	comma = strchr(token, ',');
	if (comma)
	{
		map->points[index].color = parse_hex_color(comma + 1);
		map->original_colors[index] = map->points[index].color;
	}
}

int	allocate_map_arrays(t_map *map)
{
	map->points = malloc(map->width * map->height * sizeof(t_point));
	if (!map->points)
		return (0);
	map->terrain_colors = malloc(map->width * map->height * sizeof(uint32_t));
	if (!map->terrain_colors)
		return (free(map->points), 0);
	map->original_colors = malloc(map->width * map->height * sizeof(uint32_t));
	if (!map->original_colors)
		return (free(map->points), free(map->terrain_colors), 0);
	return (1);
}

int	read_map_data(char *filepath, t_map *map)
{
	char	*line;
	int		fd;
	int		row;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (perror("open() error"), 0);
	row = 0;
	line = get_next_line(fd);
	while (line && row < map->height)
	{
		get_coordinates(map, line, row);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	if (line)
		free(line);
	return (close(fd), 1);
}
