/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:24:39 by mvoisin           #+#    #+#             */
/*   Updated: 2024/01/12 14:28:05 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack **stack)
{
	int	min;

	min = (*stack)->value;
	while ((*stack)->next)
	{
		if((*stack)->value < min)
		{
			min = ((*stack)->value);
		}
		stack = (*stack)->next;
	}
	return (min);
}