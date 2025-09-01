/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:10:45 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/28 12:40:57 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static int	ishex(int c);

int	check_file(char *filepath, int *width, int *height)
{
	char	*line;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (perror("open() error"), 0);
	line = get_next_line(fd);
	while (line && check_line(line, width) && width != 0)
	{
		free(line);
		*height += 1;
		line = get_next_line(fd);
	}
	close(fd);
	if (line != NULL || width == 0)
		return (free(line), get_next_line(-1), *width = 0, 0);
	return (1);
}

int	check_line(char *line, int *width)
{
	int	new_width;
	int	i;

	i = 0;
	new_width = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',' && ft_strncmp(&line[i], ",0x", 3) == 0)
			i += 3;
		if ((i > 3 && line[i - 1] == 'x' && !ft_ishexcolor(&line[i], &i))
			|| (line[i] && line[i] != ' ' && line[i] != '\n'))
			return (0);
		if (ft_isdigit(line[i - 1]) || ishex(line[i - 1]))
			new_width++;
	}
	if (*width == 0)
		*width = new_width;
	return (1 * (new_width != 0 && new_width == *width));
}

int	ft_ishexcolor(char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
	{
		if (!ishex(str[i]))
			return (0);
		i++;
	}
	*index += i;
	return (1);
}

static int	ishex(int c)
{
	if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A'
				&& c <= 'F')))
		return (0);
	return (1);
}
