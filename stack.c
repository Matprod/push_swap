/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:43:49 by Matprod           #+#    #+#             */
/*   Updated: 2023/12/15 18:33:29 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	return (result * sign);
}


t_stack *new_stack(int value)
{
    t_stack* new = (t_stack*)malloc(sizeof(t_stack));
    if (!new)
        return NULL;

    new->value = value;
    new->next = NULL;

    return new;
}

void stack_add_back(t_stack **stack, t_stack *new_stack)
{
	if(!new_stack)
		return ;
	if(!*stack)
	{
		*stack = new_stack;
		return ;
	}
	t_stack *temp;

	temp = *stack;
	while(temp->next)
		temp = temp->next;
	temp->next = new_stack;

}
void print_stack(t_stack *stack)
{
    while (stack)
	{
        printf("[%d]\n", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void free_stack(t_stack *stack)
{
    while (stack)
	{
        t_stack* temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main()
{
    t_stack *stack = NULL;

    t_stack *node1 = new_stack(1);
    t_stack *node2 = new_stack(2);
   // t_stack *node3 = new_stack(3);

    stack_add_back(&stack, node1);
	print_stack(stack);
	
    stack_add_back(&stack, node2);
	print_stack(stack);

/*     stack_add_back(&stack, node3);
    print_stack(stack); */

	free(stack);
	return (0);
}
