/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:04:53 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/17 15:18:23 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n)
{
	char	num[10];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n < 0)
		len += ft_putchar_fd('-', 1);
	else if (n == 0)
		return (ft_putchar_fd('0', 1));
	while (n != 0)
	{
		if (n % 10 < 0)
			num[i] = '0' - n % 10;
		else
			num[i] = '0' + n % 10;
		n /= 10;
		i++;
	}
	while (--i >= 0)
		len += ft_putchar_fd(num[i], 1);
	return (len);
}

int	ft_putuint(unsigned int n)
{
	char	num[10];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	while (n != 0)
	{
		num[i] = '0' + n % 10;
		n /= 10;
		i++;
	}
	while (--i >= 0)
		len += ft_putchar_fd(num[i], 1);
	return (len);
}

/*
int	main(int ac, char **av)
{
	printf("\n>%d<", ft_putint(atoi(av[ac - 1])));
	printf("\n*%d*", ft_putuint(atoi(av[ac - 1])));
}
*/