/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:21:56 by phunguye          #+#    #+#             */
/*   Updated: 2024/02/01 17:16:17 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_new(long int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}


void	stack_add_bottom(t_stack **stack, t_stack *new)
{

	t_stack	*last;
	
	if (*stack)
	{
		last = get_stack_bottom(*stack);
		last->next = new;
	}
	else
		*stack = new;
}


t_stack	*get_stack_bottom(t_stack *stack)
{

	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;

	return (stack);
}

//ranks the numbers according to value, starting with 1 for smallest
//goes through ptr list -> sets smallest value as 1
//assigns (t_stack)highest as stack with largest value but no index (=0)
//sets the index of current highest to stack_size (--1) for next.
void	assign_index(t_stack *stack, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
