/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:28:26 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/03 18:43:09 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **stack)
{
	int len;

	len = 1;

	if (!stack)
	{
		return 0;
	}
	while ((*stack)->next)
	{
		len++;
		*stack = (*stack)->next;
	}
	return (len);
}

/*int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_stack *stack;
	stack = stack_init(argc, argv);
	print_stack(stack);
	printf("len = %d", stack_size(&stack));

	return (1);

}*/