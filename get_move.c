/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:06:57 by mvoisin           #+#    #+#             */
/*   Updated: 2024/01/12 15:41:20 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_move(t_stack *stack_a, int nb)
{
	int	nb_move;
	
	nb_move = 0;
	if (!stack_a)
		return (0);
	while (stack_a && stack_a->value < nb)
	{	
		++nb_move;
		stack_a = stack_a->next;
	}
	return (nb_move);
}

int	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		nb_move;
	int		min;

	i = 0;
	nb_move = 0;
	min = get_moves(stack_a, stack_b->value);	
	while (stack_b)
	{
		if (get_moves(stack_a, stack_b->value) + i < min)
		{
			min = get_moves(stack_a, stack_b->value) + i;
			nb_move = i;
		}
		++i;
		stack_b = stack_b->next;
	}
	return (nb_move);
}