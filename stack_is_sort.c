/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:56:32 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/08 18:03:20 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_is_sort(t_stack **stack)
{
	if (!stack)
		return (0);
	while ((*stack)->next)
	{
		if ((*stack)->value < (*stack)->next->value)
			return (0);
		stack = (*stack)->value;
	}
	return (1);

}