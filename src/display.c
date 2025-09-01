/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:30:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:10:27 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/parser.h"

void	render_scene(t_vars *vars)
{
	ft_bzero(vars->img.addr, WINDOW_WIDTH * WINDOW_HEIGHT * 4);
	if (vars->view.animate_mode)
		draw_animated_wireframe(vars);
	else
		draw_wireframe(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	close_window(t_vars *vars)
{
	cleanup_wireframe_utils(&vars->proj_data);
	cleanup_animation(vars);
	free(vars->map->points);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->map->terrain_colors);
	free(vars->map->original_colors);
	free(vars->mlx);
	exit(0);
}

int	handle_events(t_vars *vars)
{
	static int	frame_count = 0;

	if (vars->view.animate_mode)
	{
		frame_count++;
		if (frame_count >= 800)
		{
			frame_count = 0;
			vars->view.animation_step++;
			if (vars->view.animation_step > vars->view.max_steps)
			{
				vars->view.animate_mode = 0;
				vars->view.animation_step = 0;
			}
			render_scene(vars);
		}
	}
	mlx_do_sync(vars->mlx);
	return (0);
}

int	close_mlx(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		close_window(vars);
		exit(0);
	}
	return (0);
}
