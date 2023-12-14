/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:43:49 by Matprod           #+#    #+#             */
/*   Updated: 2023/12/13 19:58:51 by Matprod          ###   ########.fr       */
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
void	*fill_stack(t_stack **stack, t_stack *new_node)
{
	
}

int main()
{

    int value = 42;
    t_stack* stack = new_stack(value);

    if (stack != NULL)
	{
        printf("Nouvel élément de pile créé avec la valeur : %d\n", stack->value);
        free(new_stack);
    }
	else
	{
        printf("Erreur lors de la création du nouvel élément de pile.\n");
    }

    return 0;
}


