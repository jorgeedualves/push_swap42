/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:49:49 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/02 14:51:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stacks *stack)
{
	if (stack->stack_a.head->data > stack->stack_a.head->next->data)
		do_print_sa(stack);
	else
		return ;
	return ;
}

void	sort_three(t_stacks *stack)
{
	int first;
	int second;
	int third;

	first = stack->stack_a.head->data;
	second = stack->stack_a.head->next->data;
	third = stack->stack_a.head->next->next->data;

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

//void    sort_five(t_stacks *stack);

void	sort_stack(t_stacks *stack)
{
	if (stack->stack_a.size == 1)
		return;
	if (stack->stack_a.size == 2)
		sort_two(stack);
	if (stack->stack_a.size == 3)
		sort_three(stack);
	// if (stack->stack_a.size > 3 && stack->stack_a.size < 6)
	//     sort_five(stack);

}