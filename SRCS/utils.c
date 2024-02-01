/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:22:47 by phunguye          #+#    #+#             */
/*   Updated: 2022/11/29 16:22:47 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/
void free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = (stack)->next;
		free(stack);
		stack = tmp;
	}
}

/* get_stack_size:
*	Returns the number of elements in a stack.
if stack is not NULL (last stack) add 1 to size
and move to next stack
*/
int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/* get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* exit_error:
*   Writes "Error\n" to the standard output after freeing stack a and b.
*	Exits with standard error code 1.
*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(*stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(*stack_b);
	write(2, "Error\n", 6);
	exit (0);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}
