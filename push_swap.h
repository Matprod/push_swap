/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:31:56 by Matprod           #+#    #+#             */
/*   Updated: 2024/01/12 15:48:15 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>


typedef struct s_stack
{
    int     value;
    int     cost_a;
    int     cost_b;
    struct  s_stack *next;
}   t_stack;


// STACK

t_stack     *new_stack(int value);
t_stack     *stack_init(int argc, char **argv);
int	        stack_size(t_stack **stack);
void        stack_add_front(t_stack **stack, t_stack *new_stack);
void	    stack_add_back(t_stack **stack, t_stack *new_node);
void        print_stack(t_stack *stack); // A REMPLACER PAR FTPRINTF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void        free_stack(t_stack *stack);
t_stack	    *stack_go_to_index(t_stack *stack, int index);
int         stack_min(t_stack **stack);


// INSTRUCTIONS

void	swap_alpha(t_stack **stack, char *Stack);
void    push_alpha(t_stack **srcstack, t_stack **deststack, char *dest);
void    rotate_down(t_stack **stack, char *str);
void    rotate_up(t_stack **stack, char *str);

// OPERATIONS

void	swap(t_stack **stack_a, t_stack **stack_b, char *move);
void	rotate(t_stack **stack_a, t_stack **stack_b, char *move);
void	rev_rotate(t_stack **stack_a, t_stack **stack_b, char *move);
void	push(t_stack **stack_a, t_stack **stack_b, char *move);
int	    do_move(t_stack **stack_a, t_stack **stack_b, char *move);

//UTILS

int     ft_atoi(const char *str);
int     ft_strlen(const char *str);
void	ft_putstr(const char *str);
int     ft_strcmp(char *s1, char *s2);
int	ft_abs(int nb);

//ALGO

t_stack     *sort_two(t_stack **stack);
t_stack     *sort_three(t_stack **stack);

//MOVES

int	get_closest(t_stack *stack, int nb);
int	get_move(t_stack *stack_a, int nb);
int	get_best_move(t_stack *stack_a, t_stack *stack_b);

//COST
int	get_cheapest_cost(t_stack *stack_b);

//ERROR

unsigned int	stack_check_duplicate(t_stack *pile);
unsigned int	check_zero(char const *str);
unsigned int	stack_special_case(int argc, char **argv);
unsigned int	check_error(int argc, char **argv, t_stack *stack);

#endif