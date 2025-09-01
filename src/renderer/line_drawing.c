/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:00:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 15:08:59 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_line_vars(t_point p1, t_point p2, int *vars)
{
	vars[0] = abs(p2.x - p1.x);
	vars[1] = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		vars[2] = 1;
	else
		vars[2] = -1;
	if (p1.y < p2.y)
		vars[3] = 1;
	else
		vars[3] = -1;
	vars[4] = vars[0] - vars[1];
}

static void	bresenham_step(int *vars, int *x, int *y)
{
	int	e2;

	e2 = 2 * vars[4];
	if (e2 > -vars[1])
	{
		vars[4] -= vars[1];
		*x += vars[2];
	}
	if (e2 < vars[0])
	{
		vars[4] += vars[0];
		*y += vars[3];
	}
}

void	draw_line(t_data *img, t_point p1, t_point p2)
{
	int	vars[5];
	int	x;
	int	y;
	int	color;

	if ((p1.x < 0 && p2.x < 0) || (p1.x >= WINDOW_WIDTH
			&& p2.x >= WINDOW_WIDTH))
		return ;
	if ((p1.y < 0 && p2.y < 0) || (p1.y >= WINDOW_HEIGHT
			&& p2.y >= WINDOW_HEIGHT))
		return ;
	init_line_vars(p1, p2, vars);
	x = p1.x;
	y = p1.y;
	color = p1.color;
	while (1)
	{
		if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
			my_mlx_pixel_put(img, x, y, color);
		if (x == p2.x && y == p2.y)
			break ;
		bresenham_step(vars, &x, &y);
	}
}
