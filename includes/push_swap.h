/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:49:46 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/10 20:18:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_node
{
	char *data;
	struct s_node *next;
	int		index;
}t_node;

typedef struct s_stack
{
	t_node  *head;
	int		size;
	int		min;
	int		max;
}t_stack;

typedef struct s_stacks
{
	t_stack  *stack_a;
	t_stack  *stack_b;
	int		limit;
	int		len;
}t_stacks;


// Push_Swap Actions
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	swap(t_node **stack);

void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);

// Call and print actions
void	do_print_sa(t_stacks *stack);
void	do_print_sb(t_stacks *stack);
void	do_print_ss(t_stacks *stack);
void	do_print_pa(t_stacks *stack);
void	do_print_pb(t_stacks *stack);
void	do_print_ra(t_stacks *stack);
void	do_print_rb(t_stacks *stack);
void	do_print_rr(t_stacks *stack);
void	do_print_rra(t_stacks *stack);
void	do_print_rrb(t_stacks *stack);
void	do_print_rrr(t_stacks *stack);

// Stack basic operations
t_node	*new_node(int data);
void	push_to_stack(t_node **stack, t_node *new_node);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_stack_a(t_stack *stack);
void	print_stack_b(t_stack *stack);
t_node	*get_bottom_element(t_node *stack);
void	append_to_stack(t_node **stack, t_node *new);
int		stack_size(t_stack stack);
void	min_max(t_stack *stack_a);

void	sort_stacks(t_stacks *stack);
void    sort_two(t_stacks *stack);
void    sort_three(t_stacks *stack);
void	sort_five(t_stacks *stack);

int		validate_args(int argc, char **argv);
int		is_integer(char *argv);
void	check_duplicates(int argc, int *num);
int		array_is_sorted(int argc, int *num);
void	transform_args(int argc, char **argv, int *num);

char	*ft_itob(int len, int num);
char	**string_bin(int len, int *num);
int		find_limit(int len);

void	init_struct(t_stacks *stacks, int argc);
void	fill_stack_a(t_stacks *stacks, char **bin, int *index);

t_stack	*ps_lstnew(char *bin, int index);
void	ps_lstadd_back(t_stack **lst, t_stack *next);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstdelone(t_stack *lst, void (*del)(void *));
t_stack	*ps_lstprevlast(t_stack *lst);
void	ps_lstadd_front(t_stack **lst, t_stack *new);

int		*quick_sort(int len, int *num);
int		*get_index(int len, int *num, int *cpy);
int		*link_index(int len, int *num);

void	push_swap(t_stacks *stacks, int *index);
void	short_push_swap(t_stacks *stacks, int *index);
void	long_push_swap(t_stacks *stacks);

void	ps_lstclear(t_stack **lst);
void	freeing(t_stacks *stacks, int *num, int *index, char **bin);
void	exit_error(void);

#endif