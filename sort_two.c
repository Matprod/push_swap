/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:47:36 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/08 18:34:15 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*sort_two(t_stack **stack)
{
	if (!stack)
		return (NULL);
	if ((*stack)->value > (*stack)->next->value)
	{
		rotate_up(&stack, "ra\n");
	}
	return (stack);
}