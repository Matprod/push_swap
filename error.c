/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:22:09 by Matprod           #+#    #+#             */
/*   Updated: 2023/12/30 14:54:50 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	stack_check_duplicate(t_stack *pile)
{
	t_stack	*stack;
	t_stack	*current;

	stack = pile;
	if (!pile)
		return (0);
	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (current->value == stack->value)
				return (0);
			current = current->next;
		}
		stack = stack->next;
	}
	return (1);
}

unsigned int	check_zero(char const *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	i--;
	while (str[++i])
	{
		if (str[i] != '0')
			return (0);
	}
	return (1);
}

unsigned int	stack_special_case(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
		{
			if (!check_zero(argv[i]))
				return (0);
			else if (argv[i][0] == '+' && !argv[i][1])
				return (0);
			else if (argv[i][0] == '-' && !argv[i][1])
				return (0);
		}
	}
	return (1);
}

unsigned int	check_error(int argc, char **argv, t_stack *stack)
{
	char	*str;

	str = NULL;
	if (!stack)
		str = "Error : Stack creation failed\n";
	else if (!stack_special_case(argc, argv))
		str = "Error : Invalid int found\n";
	else if (!stack_check_duplicate(stack))
		str = "Error : There is duplicate in the stack\n";
	else if (stack_is_sort(stack))
		str = "Error : The stack is already sort\n";
	if (str)
		return (write(STDERR_FILENO, str, ft_strlen(str)));
	return (0);
}