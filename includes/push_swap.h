/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:49:46 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/07 12:08:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
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
	t_stack  stack_a;
	t_stack  stack_b;
}t_stacks;


// Push_Swap Actions
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	swap(t_node **stack);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);

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

#endif