/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:22:18 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/13 17:23:29 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int  pos_0_greater_pos_1(int pos_0, int pos_1, int pos_2, t_stacks *stack)
{
    if (pos_1 > pos_2)
    {
        do_print_sa(stack);
        do_print_rra(stack);
        return (1);
    }
    if (pos_0 > pos_2)
    {
        do_print_ra(stack);
        return (1);
    }
    else
    {
        do_print_sa(stack);
        return (1);
    }
    return (0);
}

static int  pos_0_lower_pos_1(int pos_0, int pos_2, t_stacks *stack)
{
    if (pos_0 > pos_2)
    {
        do_print_rra(stack);
        return (1);
    }
    else
    {
        do_print_sa(stack);
        do_print_ra(stack);
        return (1);
    }
    return (0);
}

static int  three_numbers(t_stacks *stack)
{
	int pos_0;
	int pos_1;
	int pos_2;

	pos_0 = stack->stack_a->head->index;
	pos_1 = stack->stack_a->head->next->index;
	pos_2 = stack->stack_a->head->next->next->index;
	if (pos_0 < pos_1 && pos_1 < pos_2)
		return (1);
	if (pos_0 > pos_1)
	{
		pos_0_greater_pos_1 (pos_0, pos_1, pos_2, stack);
		return (1);
	}
	else
	{
		pos_0_lower_pos_1 (pos_0, pos_2, stack);
		return (1);
	}
	return (0);
}

void short_push_swap (t_stacks *stack, int *index)
{
    (void)index ; 
	if (stack->len > 3)
	{
		while (stack->stack_a->head->index != 0)
			do_print_ra(stack);
		do_print_pb(stack);
		if (stack->len == 5)
		{
			while (stack->stack_a->head->index != 1)
				do_print_ra (stack);
			do_print_pb(stack);
		}
	}
	three_numbers(stack);
	if (stack->len == 4)
		do_print_pa(stack);
	if (stack->len == 5)
	{
		do_print_pa(stack);
		do_print_pa(stack);
	}
}
