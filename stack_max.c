/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:29:56 by mvoisin           #+#    #+#             */
/*   Updated: 2024/01/12 14:30:26 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_max(t_stack **stack)
{
	int	max;

	max = (*stack)->value;
	while ((*stack)->next)
	{
		if((*stack)->value > max)
		{
			max = ((*stack)->value);
		}
		stack = (*stack)->next;
	}
	return (max);
}