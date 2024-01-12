/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:20:18 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/03 18:52:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (EXIT_FAILURE);
	stack_a = stack_init(argc, argv);
	if (check_error(argc, argv, stack_a))
	{
		free_stack(stack_a);
		return (EXIT_FAILURE);
	}
	if (stack_size(stack_a) == 2)
		stack_a = sort_two(stack_a);
	else if (stack_size(stack_a) == 3)
		stack_a = sort_three(stack_a);
	else
		stack_a = push_swap(stack_a);
	print_stack(stack_a);
	free_stack(stack_a);
	return (EXIT_SUCCESS);
}