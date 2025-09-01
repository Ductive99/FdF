/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:13:50 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:10:27 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/parser.h"

static void	init_vars(t_vars *vars, t_map *map);

int	main(int ac, char **av)
{
	t_map	map;
	t_vars	vars;

	if (ac != 2)
		return (write(2, "Usage ./fdf <filename>\n", 15), 1);
	ft_bzero(&map, sizeof(map));
	map.points = parse_map(av[1], &map);
	if (!map.points)
		return (1);
	apply_default_colors(&map);
	init_vars(&vars, &map);
	render_scene(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
	mlx_loop_hook(vars.mlx, handle_events, &vars);
	mlx_loop(vars.mlx);
	cleanup_wireframe_utils(&vars.proj_data);
	cleanup_animation(&vars);
	return (free(map.points), free(map.terrain_colors),
		free(map.original_colors), 0);
}

static void	init_vars(t_vars *vars, t_map *map)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	vars->map = map;
	vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	init_view(&vars->view);
	init_projected_data(&vars->proj_data);
	vars->flow_map = NULL;
	vars->flow_map_size = 0;
}
