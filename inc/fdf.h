/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:20:49 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:10:27 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1920
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1080
# endif

// Key codes for arrow keys
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_ESC 65307

// Key codes for WASD movement
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// Key codes for flipping
# define KEY_F 102
# define KEY_J 106

// Key codes for reverse rotation
# define KEY_G 103
# define KEY_H 104

// Key codes for Z-scale adjustment
# define KEY_Q 113
# define KEY_E 101

// Key code for Z-scale reset
# define KEY_0 48

// Key code for color scheme toggle
# define KEY_C 99

// Key code for projection toggle
# define KEY_P 112

// Key code for animation toggle
# define KEY_SPACE 32

# include "../lib/minilibx-linux/mlx.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	uint32_t			color;
}						t_point;

typedef struct s_map
{
	int					width;
	int					height;
	t_point				*points;
	int					min_z;
	int					max_z;
	uint32_t			*terrain_colors;
	uint32_t			*original_colors;
}						t_map;

typedef struct s_view
{
	int					projection;
	float				zoom;
	double				z_scale;
	int					offset_x;
	int					offset_y;
	double				x_angle;
	double				y_angle;
	double				z_angle;
	int					color_scheme;
	int					animate_mode;
	int					animation_step;
	int					max_steps;
}						t_view;

typedef struct s_projected_data
{
	t_point				*points;
	int					last_map_size;
}						t_projected_data;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	t_map				*map;
	t_data				img;
	t_view				view;
	t_projected_data	proj_data;
	int					*flow_map;
	int					flow_map_size;
}						t_vars;

void					ft_bzero(void *s, size_t n);

// Main functions
int						main(int ac, char **av);
void					print_points(t_map map);

// Event handling
int						key_handler(int keycode, t_vars *vars);
int						close_window(t_vars *vars);
int						close_mlx(int keycode, t_vars *vars);
int						handle_events(t_vars *vars);
void					handle_movement_keys(int keycode, t_vars *vars);
void					handle_z_scale_reset(int keycode, t_vars *vars);
void					handle_color_and_projection(int keycode, t_vars *vars);
void					handle_animation(int keycode, t_vars *vars);

// Initialization functions
void					init_view(t_view *view);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Display functions
void					render_scene(t_vars *vars);

t_point					project_pt(t_point *pt, t_map *map, t_view *view);
void					draw_line(t_data *img, t_point p1, t_point p2);
void					draw_wireframe(t_vars *vars);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					init_view(t_view *view);
void					init_projected_data(t_projected_data *proj_data);
void					render_scene(t_vars *vars);
uint32_t				get_earth_color(int z_value);
uint32_t				get_terrain_color(int z_value, t_map *map);
uint32_t				get_color(float t, uint32_t color_a, uint32_t color_b);
uint32_t				get_negative_terrain_color(int z_value,
							float abs_min_z);
uint32_t				get_positive_terrain_color(int z_value, float max_z);
void					precompute_terrain_colors(t_map *map);
void					apply_terrain_colors(t_map *map);
void					apply_default_colors(t_map *map);
float					calculate_scale_factor(t_map *map);

// Wireframe utility functions
t_point					*get_projected_points(t_map *map,
							t_projected_data *proj_data);
int						calculate_lod_step(int map_size, float zoom);
void					project_all_points(t_point *proj_pts, t_map *map,
							t_view *view);
void					cleanup_wireframe_utils(t_projected_data *proj_data);
void					draw_horizontal_lines(t_data *img, t_point *pts,
							t_map *map, int step);
void					draw_vertical_lines(t_data *img, t_point *pts,
							t_map *map, int step);
void					init_animation(t_vars *vars);
int						is_point_flooded(int row, int col, t_vars *vars,
							int current_step);
void					advance_water_flow(t_vars *vars, int current_step);
void					spread_basic_directions(t_vars *vars, int row, int col,
							int step);
void					spread_diagonal_directions(t_vars *vars, int row,
							int col, int step);
void					draw_animated_wireframe(t_vars *vars);
void					cleanup_animation(t_vars *vars);

#endif
