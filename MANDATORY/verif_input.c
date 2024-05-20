/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:52 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/21 00:03:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static unsigned int	check_zero(char const *str)
{
	unsigned int	i;

	i = -1;
	while (ft_is_spaces(str[++i]))
		;
	if (str[i] == '+' || str[i] == '-')
		i ++;
	i --;
	while (str[++i])
	{
		if (str[i] != '0')
			return (0);
	}
	return (1);
}

/*verif_input:
*	Verify if it's a number with an operator or not and check if there
*	is a zero.
*	Return a 0 if the input is incorrect or 1.
*/
unsigned int	verif_input(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) == 0)
		{
			if (!check_zero(av[i]))
				return (0);
			else if (av[i][0] == '+' && !av[i][1])
				return (0);
			else if (av[i][0] == '-' && !av[i][1])
				return (0);
		}
	}
	return (1);
}

static	int	ac_equal_two(int i, char **av)
{
	while (av[1][i] != '\0')
	{
		while (av[1][i] && av[1][i] == ' ')
			i++;
		if (av[1][i] == '-' || av[1][i] == '+')
		{
			if ((av[1][i + 1] >= '0' && av[1][i + 1] <= '9') && i == 0)
				i++;
			else if (av[1][i + 1] > 47 && av[1][i + 1] < 58)
			{
				if ((av[1][i - 1] == ' ') && i != 0)
					i++;
				else
					return (0);
			}
			else
				return (0);
		}
		else if ((av[1][i] >= '0' && av[1][i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	ac_more_than_two(int j, int i, char **av)
{
	while (av[i])
	{
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if ((av[i][j + 1] >= '0' && av[i][j + 1] <= '9') && j == 0)
					j++;
				else if (too_long_conditiion(av, i, j))
					j++;
				else
					return (0);
			}
			else if ((av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_between_arg(int ac, char **av)
{
	int	i;
	int	j;

	if (!av)
		return (0);
	if (ac == 2)
	{
		i = 0;
		return (ac_equal_two(i, av));
	}
	else if (ac > 2)
	{
		j = 0;
		i = 1;
		return (ac_more_than_two(j, i, av));
	}
	else
		return (0);
}
