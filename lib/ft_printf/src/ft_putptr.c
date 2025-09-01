/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:01:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/17 12:47:34 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr(uintptr_t addr)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (addr > 15)
		count += ft_puthex_ptr(addr / 16);
	count += ft_putchar_fd(hex[addr % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	if (addr == 0)
		return (write(1, "(nil)", 5), 5);
	return (ft_putstr_fd("0x", 1) + ft_puthex_ptr(addr));
}

/*
int	main(void)
{
	int	a;
	int	len1;
	int	len2;

	a = 0;
	len1 = ft_putptr(&a);
	len2 = printf("\n%p", &a);
	printf("\n%d -- %d", len1, len2);
}
*/