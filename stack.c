/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:43:49 by Matprod           #+#    #+#             */
/*   Updated: 2023/12/30 14:07:23 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *new_stack(int value)
{
    t_stack* new;
	
	new = (t_stack*)malloc(sizeof(t_stack));
    if (!new)
		return NULL;

    new->value = value;
    new->next = NULL;

    return (new);
}

void stack_add_front(t_stack **stack, t_stack *new_stack)
{
	if(!new_stack)
		return ;
	if(!*stack)
	{
		*stack = new_stack;
		return ;
	}
	new_stack->next = *stack;
    *stack = new_stack;
}
void print_stack(t_stack *stack)
{
    while (stack)
	{
        printf("[%d]", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void free_stack(t_stack *stack)
{
	if (!stack)
	{
		printf("ERROR : stack is NULL");
		return ;
	}
	t_stack		*temp;
	
    while (stack)
	{
		temp = stack;
        stack = stack->next;
        free(temp);
    }
}


/* int main()
{
    t_stack *stack1 = NULL;
	t_stack *stack2 = NULL;

    t_stack *node1 = new_stack(1);
    t_stack *node2 = new_stack(2);
   	t_stack *node3 = new_stack(3);
	t_stack *node4 = new_stack(73);

    stack_add_front(&stack1, node1);
	stack_add_front(&stack1, node2);
	stack_add_front(&stack1, node3);
    stack_add_front(&stack1, node4);
	printf("stack 1 = ");
	print_stack(stack1);
	print_stack(stack2);

	free_stack(stack1);
	free_stack(stack2);



	return (0);
} */
