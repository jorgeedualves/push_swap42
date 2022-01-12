/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:22:10 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/11 22:22:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	long_push_swap(t_stacks *stack)
{
	int	i;

	stack->limit = find_limit(stack->len);
	i = 0;
	while (stack->limit >= 0)
	{
		while (i < stack->len)
		{			
			if (stack->stack_a->index_bin[stack->limit] == '0')
				push_b(stack);
			else
				rotate(stack);
			i++;
		}
		while (stack->stack_b)
			push_a(stack);
		stack->limit--;
		i = 0;
	}
}
