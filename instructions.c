/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:22:48 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/08 18:31:28 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_up(t_stack **stack, char *str)
{
    if (*stack == NULL || (*stack)->next == NULL)
	{
        return ;
	}

	t_stack		*current;
	t_stack		*last;

	current = *stack;
    last = NULL;

    while (current)
	{
        last = current;
        current = current->next;
    }
    last->next = *stack;
    *stack = (*stack)->next;
	last->next->next = NULL;
	ft_putstr(str);
}
void rotate_down(t_stack **stack, char *str)
{
    if (*stack == NULL || (*stack)->next == NULL)
	{
        return ;
	}

	t_stack		*current;
	t_stack		*last;

	current = *stack;
    last = NULL;

    while (current->next)
	{
        last = current;
        current = current->next;
    }
	current->next = *stack;
	*stack = current;
	last->next = NULL;
	ft_putstr(str);
}

void push_alpha(t_stack **srcstack, t_stack **deststack, char *dest)
{
	if (!srcstack)
	{
		return ;
	}
	if(!deststack)
	{
		*deststack = (t_stack*)malloc(sizeof(t_stack));
	}
	t_stack *new_node;
	t_stack *tempfree;
	
	new_node = new_stack((*srcstack)->value);
	new_node->next = *deststack;
	(*deststack) = new_node;

 	tempfree = *srcstack;
	(*srcstack) = (*srcstack)->next;
	free(tempfree); 
	ft_putstr(dest);
}

void	swap_alpha(t_stack **stack, char *Stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	int		save_value;

	if (*stack && (*stack)->next)
	{
		save_value = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = save_value;
	}
	ft_putstr(Stack);
}


/*int main()
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


	printf("apres push add back \n");
	push(&stack1,&stack2);
	print_stack(stack1);
	print_stack(stack2);
	
	
	printf("\napres swap stack 1\n");
	swap(&stack1);
	print_stack(stack1);
	print_stack(stack2);


 	printf("\napres swap stack 1\n");	
	swap(&stack1);
	print_stack(stack1);
	print_stack(stack2); 
 
	printf("\napres rotate up \n");
	rotate_up(&stack1);
	print_stack(stack1); 

	printf("\napres rotate down \n");
	rotate_down(&stack1);
	print_stack(stack1);

	printf("\napres rotate down \n");
	rotate_down(&stack1);
	print_stack(stack1); 

	
	free_stack(stack1);
	free_stack(stack2);


	return (0);
}*/