/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:36:39 by phunguye          #+#    #+#             */
/*   Updated: 2022/11/18 09:36:39 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Ranks the numbers according to value, starting with 1 for smallest
//Goes through ptr list -> sets smallest value as 1
//Assigns (t_stack)highest as stack with largest value but no index (=0)
//Sets the index of current highest to stack_size (--1) for next.
void	assign_index(t_stack *stack, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

/* get_position:
*	Assigns a position to each element of a stack from top to bottom
*	in ascending order.
Example stack:
*		value:		 3	 0	 9	 2	 4	 6
*		index:		[3]	[1]	[6]	[2] [4] [5]
*		position:	<0>	<1>	<2>	<3> <4> <5>
	This is used to calculate the cost of moving a certain number to
*	a certain position. If the above example is stack b, it would cost
*	nothing (0) to push the first element to stack a. However if we want to
*	push the highest value, 9, which is in third position, it would cost 2 extra
*	moves to bring that 9 to the top of b before pushing it to stack a.
*/
void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
*	Gets the current position of the element with the lowest index
*	within a stack.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element can
*	be placed somewhere in between elements in stack A, by checking whether
*	there is an element in stack A with a bigger index. If not, it finds the
*	element with the smallest index in A and assigns that as the target position.
*	So target_pos needs to be the position of index 3, since that is
*	the "end" of the stack.
*/
/*
moves through stack a and compares element's index with the b index
if it is less, then target idx will be updated to current element's until 
element's 
index is larger than target indx.
target position is updated to element's position
then records it as ints and returns value of target_pos
*/
static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
*	Assigns a target position in stack A to each element of stack (B).
*	The target position is the spot the element in B needs to
*	get to in order to be sorted correctly. This position will
*	be used to calculate the cost of moving each element to
*	its target position in stack A.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
