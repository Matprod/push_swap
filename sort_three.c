/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:47:57 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/12 14:46:29 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack     *sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_go_to_index(stack, 0)->value;
	mid = stack_go_to_index(stack, 1)->value;
	bot = stack_go_to_index(stack, 2)->value;
	if (top > mid && bot > mid && top < bot)
		swap_alpha(stack, "sa\n");
	else if (top > mid && bot > mid && top > bot)
		rotate_up(&stack, "ra\n");
	else if (top > mid && mid > bot)
	{
		swap_alpha(stack, "sa\n");
		rotate_down(&stack, "rra\n");
	}
	else if (top < mid && mid > bot && top > bot)
		rotate_down(&stack, "rra\n");
	else if (top < mid && mid > bot && top < bot)
	{
		swap_alpha(stack, "sa\n");
		rotate_up(&stack, "ra\n");
	}
	return (stack);
}