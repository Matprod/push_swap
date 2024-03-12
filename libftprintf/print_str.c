/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:56:23 by mvoisin           #+#    #+#             */
/*   Updated: 2024/03/12 18:01:45 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	print_str(char *s)
{
	int	len;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = write(1, s, ft_strlen_printf(s));
	return (len);
}
