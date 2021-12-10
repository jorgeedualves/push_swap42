/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:24:26 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/10 20:25:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_two(t_stacks *stack)
{
    if (stack->stack_a->head->data > stack->stack_a->head->next->data)
        do_print_sa(stack);
    return ;
}

void    sort_three(t_stacks *stack)
{
    char *first;
    char *second;
    char *third;

    first = stack->stack_a->head->data;
    second = stack->stack_a->head->next->data;
    third = stack->stack_a->head->next->next->data;

	if (first > second && second > third && first > third)
	{
		do_print_sa(stack);
		do_print_rra(stack);
	}
	else if (first < second && second > third && first < third)
	{
		do_print_rra(stack);
		do_print_sa(stack);
	}
	else if (first > second && second < third && first < third)
		do_print_sa(stack);
	else if (first < second && second > third && first > third)
		do_print_rra(stack);
	else if (first > second && second < third && first > third)
		do_print_ra(stack);
    else if (first < second && second < third)
        return ;
}

void    sort_five(t_stacks *stack)
{
	if (stack->stack_a->size == 4)
	{
		do_print_pb(stack);
		sort_three(stack);
	}
	if (stack->stack_a->size == 5)
	{
		do_print_pb(stack);
		do_print_pb(stack);
		sort_three(stack);
		sort_two(stack);
		do_print_pa(stack);
		do_print_pa(stack);
	}

}

void	sort_stacks(t_stacks *stack)
{
    if (stack->stack_a->size == 1)
        return;
    if (stack->stack_a->size == 2)
         sort_two(stack);   
    if (stack->stack_a->size == 3)
         sort_three(stack);
}
