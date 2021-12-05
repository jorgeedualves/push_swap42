/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:16:49 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/05 17:46:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_print_sa(t_stacks *stacks)
{
	swap(&stacks->stack_a->head);
	write(1, "sa\n", 3);
}

void	do_print_sb(t_stacks *stacks)
{
	swap(&stacks->stack_b->head);
	write(1, "sb\n", 3);
}

void	do_print_ss(t_stacks *stack)
{
	swap(&stack->stack_a->head);
	swap(&stack->stack_b->head);
	write(1, "ss\n", 3);
}

void	do_print_ra(t_stacks *stack)
{
	reverse_rotate(&stack->stack_a->head);
	write(1, "ra\n", 3);
}

void	do_print_rb(t_stacks *stack)
{
	reverse_rotate(&stack->stack_b->head);
	write(1, "rb\n", 3);
}

void	do_print_rr(t_stacks *stack)
{
	rotate(&stack->stack_a->head);
	rotate(&stack->stack_b->head);
	write(1, "rr\n", 3);
}

void	do_print_rra(t_stacks *stack)
{
	reverse_rotate(&stack->stack_a->head);
	write(1, "rra\n", 4);
}

void	do_print_rrb(t_stacks *stack)
{
	reverse_rotate(&stack->stack_b->head);
	write(1, "rrb\n", 4);
}

void	do_print_rrr(t_stacks *stack)
{
	reverse_rotate(&stack->stack_a->head);
	reverse_rotate(&stack->stack_b->head);
	write(1, "rrr\n", 4);
}

void	do_print_pa(t_stacks *stack)			// OK
{
	push_a(&(*stack->stack_a), &(*stack->stack_b));
	write(1, "pa\n", 3);
}

void	do_print_pb(t_stacks *stack)			//	OK
{
	push_b(&(*stack->stack_a), &(*stack->stack_b));
	write(1, "pb\n", 3);
}
