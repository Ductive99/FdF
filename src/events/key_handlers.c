/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:57:57 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_movement_keys(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		vars->view.offset_x += 20;
	else if (keycode == KEY_D)
		vars->view.offset_x -= 20;
	else if (keycode == KEY_W)
		vars->view.offset_y += 20;
	else if (keycode == KEY_S)
		vars->view.offset_y -= 20;
}

void	handle_z_scale_reset(int keycode, t_vars *vars)
{
	if (keycode == KEY_0)
		vars->view.z_scale = 1.0;
}

void	handle_color_and_projection(int keycode, t_vars *vars)
{
	if (keycode == KEY_C)
	{
		vars->view.color_scheme = !vars->view.color_scheme;
		if (vars->view.color_scheme)
			apply_terrain_colors(vars->map);
		else
			apply_default_colors(vars->map);
	}
	else if (keycode == KEY_P)
		vars->view.projection = (vars->view.projection + 1) % 3;
}

void	handle_animation(int keycode, t_vars *vars)
{
	if (keycode == KEY_SPACE)
	{
		if (vars->view.animate_mode == 0)
			init_animation(vars);
		else
		{
			vars->view.animate_mode = 0;
			vars->view.animation_step = 0;
		}
	}
}
