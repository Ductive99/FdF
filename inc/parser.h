/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:12:23 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:23:35 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fdf.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/stat.h>

typedef struct s_point	t_point;
typedef struct s_map	t_map;

int						ft_printf(const char *format, ...);

char					*get_next_line(int fd);
char					**ft_split(char const *s, char c);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

int						check_file(char *filepath, int *width, int *height);
int						check_line(char *line, int *width);
int						ft_ishexcolor(char *str, int *index);

t_point					*parse_map(char *filepath, t_map *map);

t_point					*fill_map(char *filepath, t_map *map);

/* map_builder_utils.c */
void					free_tokens(char **tokens);
void					process_token(t_map *map, char *token, int row,
							int col);
int						allocate_map_arrays(t_map *map);
int						read_map_data(char *filepath, t_map *map);

/* color_parser.c */
int						parse_hex_color(char *hex_str);

void					get_coordinates(t_map *map, char *line, int row);
void					set_points(t_map *map);

#endif
