/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:46:39 by mvoisin           #+#    #+#             */
/*   Updated: 2024/01/12 15:49:06 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_stack *stack_a, int nb)
{
	int	index;

	if (!stack_a)
		return (0);
	index = stack_go_to_index(stack_a, get_nearest(stack_a, nb));
	if (index > (int)stack_size(stack_a) / 2)
		return (-(stack_size(stack_a) - index));
	return (index);
}

void	init_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;

	size = stack_size(stack_b);
	i = 0;
	while (stack_b)
	{
		stack_b->cost_a = cost_a(stack_a, stack_b->value);
		stack_b->cost_b = i;
		if (i > size / 2)
			stack_b->cost_b = -(size - i);
		++i;
		stack_b = stack_b->next;
	}
}

int	get_cheapest_cost(t_stack *stack_b)
{
	int	min;
	int	index_node;
	int	i;

	min = 2147483647;
	i = 0;
	while (stack_b)
	{
		if (ft_abs(stack_b->cost_b) + ft_abs(stack_b->cost_a) < min)
		{
			min = ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b);
			index_node = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	return (index_node);
}