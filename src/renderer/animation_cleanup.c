/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:06:42 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	cleanup_animation(t_vars *vars)
{
	if (vars->flow_map)
	{
		free(vars->flow_map);
		vars->flow_map = NULL;
		vars->flow_map_size = 0;
	}
}
