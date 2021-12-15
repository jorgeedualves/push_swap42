/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:22:18 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 22:02:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	two_numbers(t_stacks *stack)
{
	reverse_rotate(stack);
	return (0);
}

static int	three_numbers(t_stacks *stack)
{
	int	pos_0;
	int	pos_1;
	int	pos_2;

	pos_0 = stack->stack_a->index;
	pos_1 = stack->stack_a->next->index;
	pos_2 = stack->stack_a->next->next->index;
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

static int	sort_four_or_five(t_stacks *stack, int *index)
{
	if (index[5] == 0)
		reverse_rotate(stack);
	while (stack->stack_a->index != 0)
		rotate(stack);
	push_b(stack);
	if (stack->len == 5)
	{
		while (stack->stack_a->index != 1)
			rotate(stack);
		push_b(stack);
	}
	three_numbers(stack);
	if (stack->len == 4)
		push_a(stack);
	if (stack->len == 5)
	{
		push_a(stack);
		push_a(stack);
	}
	return (0);
}

void	short_push_swap(t_stacks *stack, int *index)
{
	if (stack->len == 2)
		two_numbers(stack);
	else if (stack->len == 3)
	{
		three_numbers(stack);
		return ;
	}
	else if (stack->len > 3)
		sort_four_or_five(stack, index);
	(void) index;
}
