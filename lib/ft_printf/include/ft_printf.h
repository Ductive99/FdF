/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:40:02 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/27 13:51:49 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <aio.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_putint(int n);
int		ft_putuint(unsigned int n);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putchar_fd(int c, int fd);
int		ft_puthex(unsigned int n, int c);
int		ft_putptr(void *ptr);
size_t	ft_strlen(const char *s);

int		do_op(char c, va_list args);

#endif
