/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:15 by phunguye          #+#    #+#             */
/*   Updated: 2024/05/24 12:22:37 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	write_and_free(char *line)
{
	write(1, "Error\n", ft_strlen("Error\n"));
	free(line);
}

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		nb;

	line = "begin";
	while (line)
	{
		line = get_next_line(0);
		if (line && !ft_strcmp(line, "Error"))
		{
			write_and_free(line);
			return (-1);
		}
		else if (do_move_bonus(stack_a, stack_b, line) != -1)
		{
			free(line);
			return (1);
		}
		else
		{
			write_and_free(line);
			return (-1);
		}
		free(line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		nb;

	stack_a = NULL;
	stack_b = NULL;
	if (check_between_arg(ac, av) == 0)
		return (write(STDERR_FILENO, "Error\n", ft_strlen("Error\n")));
	stack_a = stack_init(ac, av, stack_a);
	nb = checker(&stack_a, &stack_b);
	if (nb == -1)
		return (EXIT_FAILURE);
	else if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}
//print_stack(stack_a);
