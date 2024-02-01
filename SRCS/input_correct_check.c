/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_correct_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:17:30 by phunguye          #+#    #+#             */
/*   Updated: 2024/01/30 16:34:02 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


unsigned int	contains_duplicates(t_stack *stack)
{
	t_stack	*begin;
	t_stack	*current;

	begin = stack;
	if (!stack)
		return (0);
	while (begin)
	{
		current = begin->next;
		while (current)
		{
			if (current->value == begin->value)
				return (1);
			current = current->next;
		}
		begin = begin->next;
	}
	return (0);
}

unsigned int	check_error(int argc, char **argv, t_stack *stack)
{
	char	*str;

	str = NULL;
	if (!stack)
		str = "Error\n";
	else if (!verif_input(argc, argv))
		str = "Error\n";
	else if (contains_duplicates(stack))
		str = "Error\n";
	else if (is_sorted(stack))
		str = "Error\n";
	if (str)
		return (write(STDERR_FILENO, str, ft_strlen(str)));
	return (0);
}
