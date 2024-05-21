/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:15 by phunguye          #+#    #+#             */
/*   Updated: 2024/05/21 13:48:58 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = "begin";
	while (line)
	{
		line = get_next_line(0);
		if (do_move_bonus(stack_a, stack_b, line))
		{
			free(line);
			return ;
		}
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_between_arg(ac, av) == 0)
		return (write(STDERR_FILENO, "Error\n", ft_strlen("Error\n")));
	stack_a = stack_init(ac, av, stack_a);
	if (check_error(ac, av, stack_a))
	{
		free_stack(stack_a);
		return (EXIT_FAILURE);
	}
	checker(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}
//print_stack(stack_a);
