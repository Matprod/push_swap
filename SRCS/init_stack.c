/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:38:39 by Matprod           #+#    #+#             */
/*   Updated: 2024/02/01 18:09:06 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *stack_fill(t_stack *stack_a,int size, char **av, int i)
{

	t_stack	*new;

	while (i < size)
	{
		new = stack_new(ft_atoi(av[i]));
		if (!new)
		{
			free_stack(new);
			return (NULL);
		}
		if(!stack_a)
		{
			stack_a = stack_new(new->value);
			free_stack(new);
		}
		else
			stack_add_bottom(&stack_a, new);
		i++;
	}

	return(stack_a);

}

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
	return(stack_a);
}

