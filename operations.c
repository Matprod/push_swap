/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:16:37 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/08 18:32:40 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap_alpha(*stack_a, "sa\n");
	else if (!ft_strcmp(move, "sb\n"))
		swap_alpha(*stack_b, "sb\n");
	else if (!ft_strcmp(move, "ss\n"))
	{
		swap_alpha(*stack_a, "sa\n");
		swap_alpha(*stack_b, "sb\n");
	}
}

void	rotate(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "ra\n"))
		rotate_up(stack_a,"ra\n");
	else if (!ft_strcmp(move, "rb\n"))
		rotate_up(stack_b,"rb\n");
	else if (!ft_strcmp(move, "rr\n"))
	{
		rotate_up(stack_a, "ra\n");
		rotate_up(stack_b, "rb\n");
	}
}

void	rev_rotate(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "rra\n"))
		rotate_down(stack_a, "rra");
	else if (!ft_strcmp(move, "rrb\n"))
		rotate_down(stack_b, "rrb\n");
	else if (!ft_strcmp(move, "rrr\n"))
	{
		rotate_down(stack_a, "rra\n");
		rotate_down(stack_b, "rrb\n");
	}
}

void	push(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		do_push(stack_b, stack_a);
	else if (!ft_strcmp(move, "pb\n"))
		do_push(stack_a, stack_b);
}

int	do_move(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!move)
		return (1);
	if (!ft_strcmp(move, "sa\n") || !ft_strcmp(move, "sb\n")
		|| !ft_strcmp(move, "ss\n"))
		swap(stack_a, stack_b, move);
	else if (!ft_strcmp(move, "rra\n") || !ft_strcmp(move, "rrb\n")
		|| !ft_strcmp(move, "rrr\n"))
		rev_rotate(stack_a, stack_b, move);
	else if (!ft_strcmp(move, "ra\n") || !ft_strcmp(move, "rb\n")
		|| !ft_strcmp(move, "rr\n"))
		rotate(stack_a, stack_b, move);
	else if (!ft_strcmp(move, "pa\n") || !ft_strcmp(move, "pb\n"))
		push(stack_a, stack_b, move);
	else
		return (write(2, "Error with the move\n", 21));
	return (0);
}