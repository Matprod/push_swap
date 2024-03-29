/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:38:16 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/12 16:38:16 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*swaps the first two elements of the stack that is passed to it*/
//can I rewrite with [][]? strings?
void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp_value = stack->value;
	tmp_index = stack->index;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->next->value = tmp_value;
	stack->next->index = tmp_index;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
