/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:59:56 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 13:51:49 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

int	ft_putstr_fd(const char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	if (!str)
		return (write(fd, "(null)", 6), 6);
	if (str)
		write(fd, str, len);
	return ((int)len);
}
