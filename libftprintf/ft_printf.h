/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:43:03 by mvoisin           #+#    #+#             */
/*   Updated: 2024/03/12 18:01:15 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);

int		print_char(char c);

int		ft_strlen_printf(char *s);

void	ft_putstr(char *s);

int		print_str(char *s);

void	ft_putnbr(int n);

int		print_nbr(int n);

void	putnbr_base(unsigned long n, char *base);

void	put_unsigned_number(unsigned int n);

int		print_unsigned_nbr(unsigned int n);

int		print_percent(void);

int		print_ptr(unsigned long ptr);

int		print_hex(unsigned int num);

int		print_hex_caps(unsigned int num);

int		check_format(va_list args, char c);

int		ft_printf(const char *str, ...);

#endif