/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:18:08 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/15 10:50:41 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static int	ft_isspace(int c);
static int	check_int_overflow(const char *str);
static int	check_length(const char *str);

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign * check_int_overflow(str));
}

static int	check_int_overflow(const char *str)
{
	char	*_int;
	int		len;
	int		i;

	i = -1;
	len = check_length(str);
	if (len != 10)
		return (len < 10);
	_int = "2147483647";
	while (*str == ' ')
		str++;
	len = -1;
	if (*str == '-' || *str == '+')
		len++;
	while (str[len + 1] == '0' && ++len >= 0)
		;
	while (_int[++i] && ++len >= 0 && i < 9)
		if (_int[i] != str[len])
			return (_int[i] > str[len]);
	return ((_int[9] + (int)(*str == '-')) >= \
		str[len]);
}

static int	check_length(const char *str)
{
	int	len;
	int	zeros;

	len = 0;
	zeros = 0;
	if (!str)
		return (0);
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (str[zeros] == '0' && ++zeros)
		;
	while (str[zeros + len] >= '0' && str[zeros + len] <= '9')
		len++;
	return (len);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
