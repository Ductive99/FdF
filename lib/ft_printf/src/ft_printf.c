/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:40:21 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/17 15:21:24 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar_fd(*format, 1);
		else if (*(format + 1))
			len += do_op(*++format, args);
		format++;
	}
	va_end(args);
	return (len);
}

/*
int	main(int ac, char **av)
{
	const char	*s = av[ac - 1];

	int std, ft;
	ft = ft_printf("Hello, %p", &s);
	printf("\n\t<>\t<>\n");
	std = printf("Hello, %p", &s);
	printf("\n\t<>\t<>\n");
	printf("std: %d\tft: %d\n", std, ft);
}
*/