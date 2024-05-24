/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_correct_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:17:30 by phunguye          #+#    #+#             */
/*   Updated: 2024/05/24 10:42:38 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* contains_duplicates:
*Check if there are duplicates number
*return 1 for duplicates or 0
*/
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
		return (write(1, str, ft_strlen(str)));
	return (0);
}
