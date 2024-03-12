/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:15 by phunguye          #+#    #+#             */
/*   Updated: 2024/03/10 20:18:31 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	The summit of the algo,
*	Check if there are two numbers and if it's sorted
*	Then check if there are three numbers
*	Call the function 'sort' for starting the algorythm
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	This programs start with checking if the argument are correct
*	Then we create the stack and fill it zith the numbers
*	Afterthat, it check if there are any errors in the stack
*	Then we assign an index for every numbers of the stack
*	And we call the algo and free every stacks at the end
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = NULL;
	if (check_between_arg(ac, av) == 0)
		return (write(STDERR_FILENO, "Error\n", ft_strlen("Error\n")));
	else
		stack_a = stack_init(ac, av, stack_a);
	if (check_error(ac, av, stack_a))
	{
		free_stack(stack_a);
		return (EXIT_FAILURE);
	}
	stack_b = NULL;
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
}
//print_stack(stack_a);
