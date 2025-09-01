/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:28:00 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/30 18:23:35 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int	parse_hex_color(char *hex_str)
{
	int	color;

	color = 0;
	if (*hex_str != '0' || (*(hex_str + 1) != 'x' && *(hex_str + 1) != 'X'))
		return (0xFFFFFF);
	hex_str += 2;
	while ((*hex_str >= '0' && *hex_str <= '9') || (*hex_str >= 'a'
			&& *hex_str <= 'f') || (*hex_str >= 'A' && *hex_str <= 'F'))
	{
		color <<= 4;
		if (*hex_str >= '0' && *hex_str <= '9')
			color |= *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			color |= *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			color |= *hex_str - 'A' + 10;
		hex_str++;
	}
	return (color);
}
