/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:11:51 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 13:47:27 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_point	*parse_map(char *filepath, t_map *map)
{
	if (!check_file(filepath, &map->width, &map->height))
		return (ft_printf("Map Error\n"), NULL);
	ft_printf("Map dimensions: %dx%d\n", map->width, map->height);
	return (fill_map(filepath, map));
}
