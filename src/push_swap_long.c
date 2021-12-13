/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:22:10 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/13 17:28:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	long_push_swap (t_stacks *stack)
{
	int i;

	stack->limit = find_limit(stack->len);
	i = 0;
	while (stack->limit >= 0)
	{
		while (i < stack->len)
		{
			if (stack->stack_a->head->data[stack->limit] == '0')
				do_print_pb(stack);
			else
				do_print_ra(stack);
			i++;
		}
		while (stack->stack_b)
			do_print_pa(stack);
		stack->limit--;
		i = 0;
	}
}
