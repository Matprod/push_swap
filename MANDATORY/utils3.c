/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:27:33 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/21 18:43:16 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libftprintf/libft/libft.h"

/*too_long_conditiion:
* Everything is in the name ......................
*/
int	too_long_conditiion(char **av, int i, int j)
{
	if (av[i][j + 1] >= 48 && av[i][j + 1] <= 57)
	{
		if ((av[i][j - 1] == ' ') && j != 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

long int	ft_atoi_ps(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	if (result > INT_MAX || result < INT_MIN)
		return (2147483648);
	return (result * sign);
}
