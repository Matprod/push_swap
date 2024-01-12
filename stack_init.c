/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:10:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/02 15:38:01 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*stack_init(int argc, char **argv)
{
	t_stack	*stack;
	t_stack *node;
	int 	i;

	stack = NULL;
	i = 0;
	while (++i < argc)
	{
		node = new_stack(ft_atoi(argv[i]));
		if(!node)
		{
			free_stack(stack);
			return NULL;
		}
		stack_add_back(&stack, node);
	}
	return (stack);
}

/*int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_stack *stack;
	stack = stack_init(argc, argv);
	print_stack(stack);

	return (1);

}*/