/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:02:14 by mvoisin           #+#    #+#             */
/*   Updated: 2024/01/12 15:48:08 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_closest(t_stack *stack, int nb)
{
	int	closest;

	closest = 2147483647;
	while (stack)
	{
		if (stack->value > nb && stack->value < closest)
			closest = stack->value;
		stack = stack->next;
	}
	return (closest);
}