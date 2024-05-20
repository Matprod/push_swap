/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:07 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/12 18:27:07 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 42
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libftprintf/ft_printf.h"
# include "./libftprintf/libft/libft.h"

typedef struct s_stack
{
	long int				value;
	int						index;
	int						pos;
	int						target_pos;
	int						cost_a;
	int						cost_b;
	struct s_stack			*next;
}	t_stack;

/* Initialization */

t_stack		*stack_fill(t_stack *stack_a, int size, char **av, int i);
void		assign_index(t_stack *stack_a, int ac);

/* Sorting Algorithms */

int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position */

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

/* Stack Functions */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(long int value);
void		stack_add_bottom(t_stack **stack, t_stack *newstack);
int			get_stack_size(t_stack	*stack);

/* Utils */

void		free_stack(t_stack *stack);
void		free_array(char **array);
long int	ft_atol(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		print_stack(t_stack *stack);
size_t		ft_wordcount(char const *s, char c);
int			ft_charset_in(char c, char charset);
unsigned	int	ft_is_spaces(char c);
int			too_long_conditiion(char **av, int i, int j);
long int	ft_atoi_ps(const char *str);

/* Error */

void		exit_error(t_stack **stack_a, t_stack **stack_b);
unsigned	int	verif_input(int ac, char **av);
unsigned	int	check_error(int argc, char **argv, t_stack *stack);

/* Input Check */
int			check_between_arg(int ac, char **av);
int			input_correct_check(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
t_stack		*stack_init(int argc, char **argv, t_stack *stack_a);

/*		GNL		*/
char		*get_next_line(int fd);

char		*read_and_stock(int fd, char *stack);

size_t		ft_strlen(const char *s);

char		*ft_strjoin_gnl(char *s1, char const *s2);

int			ft_strchr_gnl(const char *s, int c);

char		*ft_strdup(const char *s);

/*		BONUS     */

char		**dup_map(int argc, char **argv);

void		push(t_stack **src, t_stack **dst);

void		rev_rotate(t_stack **stack);

void		swap(t_stack *stack);

void		rotate(t_stack **stack);

int			do_move_bonus(t_stack **stack_a, t_stack **stack_b, char *move);

int			ft_strcmp(const char *s1, const char *s2);

#endif