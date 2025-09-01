/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 03:54:17 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 13:51:49 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*new;

	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			new[i++] = *s1++;
	if (s2)
		while (*s2)
			new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	if (src)
		while (*src)
			dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			size;
	unsigned int	i;

	i = 0;
	size = ft_strlen(s);
	if (start >= size)
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (start + i < size && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
