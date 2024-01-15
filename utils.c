/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:38:53 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/12 14:50:39 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	return (result * sign);
}
int ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}


int ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while ((!s1 || !*s2) && (s1[i] == s2[i]))
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}