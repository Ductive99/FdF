/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:30:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 17:57:57 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/parser.h"

static void	handle_zoom_rotation_keys(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP && vars->view.zoom < 10.0)
		vars->view.zoom += 0.1;
	else if (keycode == KEY_DOWN && vars->view.zoom > 0.1)
		vars->view.zoom -= 0.1;
	else if (keycode == KEY_LEFT)
		vars->view.z_angle -= 0.1;
	else if (keycode == KEY_RIGHT)
		vars->view.z_angle += 0.1;
	else if (keycode == KEY_F)
		vars->view.x_angle += 0.1;
	else if (keycode == KEY_G)
		vars->view.x_angle -= 0.1;
	else if (keycode == KEY_J)
		vars->view.y_angle += 0.1;
	else if (keycode == KEY_H)
		vars->view.y_angle -= 0.1;
}

static void	handle_z_scale_keys(int keycode, t_vars *vars)
{
	double	adjustment;

	if (keycode == KEY_Q && vars->view.z_scale > 0.001)
	{
		if (vars->view.z_scale > 1.0)
			adjustment = 0.1;
		else if (vars->view.z_scale > 0.1)
			adjustment = 0.01;
		else
			adjustment = 0.001;
		vars->view.z_scale -= adjustment;
		if (vars->view.z_scale < 0.001)
			vars->view.z_scale = 0.001;
	}
	else if (keycode == KEY_E)
	{
		if (vars->view.z_scale < 0.1)
			adjustment = 0.001;
		else if (vars->view.z_scale < 1.0)
			adjustment = 0.01;
		else
			adjustment = 0.1;
		vars->view.z_scale += adjustment;
	}
}

static void	handle_other_keys(int keycode, t_vars *vars)
{
	handle_z_scale_reset(keycode, vars);
	handle_color_and_projection(keycode, vars);
	handle_animation(keycode, vars);
}

static void	handle_key_groups(int keycode, t_vars *vars)
{
	handle_movement_keys(keycode, vars);
	handle_zoom_rotation_keys(keycode, vars);
	handle_z_scale_keys(keycode, vars);
	handle_other_keys(keycode, vars);
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_window(vars);
	handle_key_groups(keycode, vars);
	render_scene(vars);
	return (0);
}
