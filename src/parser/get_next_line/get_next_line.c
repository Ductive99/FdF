/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:57 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/24 18:30:25 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(holder), holder = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, holder, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	holder = set_line(line);
	return (line);
}

char	*read_line(int fd, char *rest, char *buffer)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (free(rest), NULL);
		else if (!ret)
			break ;
		buffer[ret] = '\0';
		if (!rest)
			rest = ft_strdup("");
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

char	*set_line(char *line)
{
	char	*rest;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	line[i + 1] = '\0';
	return (rest);
}
