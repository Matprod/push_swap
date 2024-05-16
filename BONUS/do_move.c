/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:36:00 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/12 16:36:00 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap(*stack_a);
	else if (!ft_strcmp(move, "sb\n"))
		swap(*stack_b);
	else if (!ft_strcmp(move, "ss\n"))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
}

void	do_rotate(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(move, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	do_rev_rotate(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "rra\n"))
		rev_rotate(stack_a);
	else if (!ft_strcmp(move, "rrb\n"))
		rev_rotate(stack_b);
	else if (!ft_strcmp(move, "rrr\n"))
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
}

void	do_push(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(move, "pb\n"))
		push(stack_a, stack_b);
}

int	do_move_bonus(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!move)
		return (1);
	if (!ft_strcmp(move, "sa\n") || !ft_strcmp(move, "sb\n")
		|| !ft_strcmp(move, "ss\n"))
		do_swap(stack_a, stack_b, move);
	else if (!ft_strcmp(move, "ra\n") || !ft_strcmp(move, "rb\n")
		|| !ft_strcmp(move, "rr\n"))
		do_rotate(stack_a, stack_b, move);
	else if (!ft_strcmp(move, "rra\n") || !ft_strcmp(move, "rrb\n")
		|| !ft_strcmp(move, "rrr\n"))
		do_rev_rotate(stack_a, stack_b, move);
	else if (!ft_strcmp(move, "pa\n") || !ft_strcmp(move, "pb\n"))
		do_push(stack_a, stack_b, move);
	else
		return (write(2, "Error : Wrong operation\n", 24));
	return (0);
}
