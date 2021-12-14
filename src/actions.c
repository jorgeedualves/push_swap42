/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:12:58 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 04:26:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stacks *stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack->stack_a)
	{
		first = stack->stack_a;
		last = stack->stack_a;
		while (last->next != NULL)
			last = last->next;
		stack->stack_a = first->next;
		first->next = NULL;
		last->next = first;
		ft_putstr_fd("ra\n", 1);
	}
}

void	reverse_rotate(t_stacks *stack)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (stack->stack_a)
	{
		last = stack->stack_a;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = stack->stack_a;
		stack->stack_a = last;
		ft_putstr_fd("rra\n", 1);
	}
}

void	swap(t_stacks *stack)
{
	char	*temp_a;
	char	*temp_b;

	if (stack->stack_a)
	{
		temp_a = stack->stack_a->data;
		temp_b = stack->stack_a->next->data;
		stack->stack_a->data = temp_b;
		stack->stack_a->next->data = temp_a;
		ft_putstr_fd("sa\n", 1);
	}
}

void	push_b(t_stacks *stack)
{
	t_stack	*first;

	if (stack->stack_a)
	{
		first = stack->stack_a;
		stack->stack_a = first->next;
		first->next = stack->stack_b;
		stack->stack_b = first;
		ft_putstr_fd("pb\n", 1);
	}
}

void	push_a(t_stacks *stack)
{
	t_stack	*first;

	if (stack->stack_b)
	{
		first = stack->stack_b;
		stack->stack_b = first->next;
		first->next = stack->stack_a;
		stack->stack_a = first;
		ft_putstr_fd("pa\n", 1);
	}
}
