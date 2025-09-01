/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:03:12 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/17 15:21:50 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_op(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}
