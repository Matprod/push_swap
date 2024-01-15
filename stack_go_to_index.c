/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_go_to_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:04:56 by mvoisin           #+#    #+#             */
/*   Updated: 2024/01/12 14:07:42 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_go_to_index(t_stack *stack, int index)
{
	while (index--)
		stack = stack->next;
	return (stack);
}