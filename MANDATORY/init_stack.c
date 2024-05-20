/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:38:39 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/21 00:02:18 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* stack_fill:
* Create and fill the stack A with every numbers in the argv
*/

static int	if_more_than_int(t_stack *stack_a, char **av, int i)
{
	if (ft_atoi_ps(av[i]) == 0)
	{
		if (stack_a)
			free_stack(stack_a);
		return (0);
	}
	return (1);
}

t_stack	*stack_fill(t_stack *stack_a, int size, char **av, int i)
{
	t_stack	*new;

	while (i < size)
	{
		if (if_more_than_int(stack_a, av, i) == 0)
			return (NULL);
		new = stack_new(ft_atoi_ps(av[i]));
		if (!new)
		{
			free_stack(new);
			return (NULL);
		}
		if (!stack_a)
		{
			stack_a = stack_new(new->value);
			free_stack(new);
		}
		else
			stack_add_bottom(&stack_a, new);
		i++;
	}
	return (stack_a);
}

/* stack_init:
*	Check if there are 2 arguments in argv or if it's more than 3,
*	(2 for a string with space between every number
*	 3 for multiple string in the argv)
*	Then split the space if it's two and fill the stack or just fill
*/
t_stack	*stack_init(int argc, char **argv, t_stack *stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		stack_a = stack_fill(stack_a, size, arg, 0);
		free_array(arg);
	}
	else if (argc >= 3)
		stack_a = stack_fill(stack_a, argc, argv, 1);
	return (stack_a);
}
