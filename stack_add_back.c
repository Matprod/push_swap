/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:36:29 by Matprod           #+#    #+#             */
/*   Updated: 2023/12/30 14:50:18 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
	
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack *last_node;

	if(!new_node)
		return ;
	if(!*stack)
	{
		*stack = new_node;
		return ;
	}
	last_node = stack_last(*stack);
	last_node->next = new_node;
}

