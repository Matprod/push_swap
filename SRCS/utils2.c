/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:21:20 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/12 16:16:10 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libftprintf/libft/libft.h"

unsigned int	ft_is_spaces(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("[%d] ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

long int	ft_atol(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

int	ft_charset_in(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}
