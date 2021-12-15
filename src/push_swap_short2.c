/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:59:56 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 22:05:04 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pos_0_greater_pos_1(int pos_0, int pos_1, int pos_2,
								t_stacks *stack)
{
	if (pos_1 > pos_2)
	{
		swap(stack);
		reverse_rotate(stack);
		return (1);
	}
	if (pos_0 > pos_2)
	{
		rotate(stack);
		return (1);
	}
	else
	{
		swap(stack);
		return (1);
	}
	return (0);
}

int	pos_0_lower_pos_1(int pos_0, int pos_2, t_stacks *stack)
{
	if (pos_0 > pos_2)
	{
		reverse_rotate(stack);
		return (1);
	}
	else
	{
		swap(stack);
		rotate(stack);
		return (1);
	}
	return (0);
}
