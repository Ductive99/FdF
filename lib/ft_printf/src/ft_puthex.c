/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:46:17 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/17 12:37:41 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int c)
{
	char	*hex;
	int		len;
	int		diff;

	hex = "0123456789abcdef";
	diff = 'x' - c;
	len = 0;
	if (n > 15)
		len += ft_puthex(n / 16, c);
	if (n % 16 > 9)
		len += ft_putchar_fd(hex[n % 16] - diff, 1);
	else
		len += ft_putchar_fd(hex[n % 16], 1);
	return (len);
}

/*
int	main(int ac, char **av)
{
	int	n;

	n = atoi(av[ac - 1]);
	printf("%x\n", n);
	ft_puthex(n, 'X');
}
*/