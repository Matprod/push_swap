/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:27:33 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/21 00:03:57 by Matprod          ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index ++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
