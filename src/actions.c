/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:07:38 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/30 23:21:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rotate(t_node **stack)
{
	t_node *temp;
	
	temp = *stack;
	*stack = (*stack)->next;
	append_to_stack(&(*stack), temp);
	temp->next = NULL;
}

void reverse_rotate(t_node **stack)
{
	t_node *last;
	t_node *temp;

	temp = *stack;
	last = get_bottom_element(temp);
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			temp->next = NULL;
		else
			temp = temp->next;
	}
	push_to_stack(stack, last);
}

void swap(t_node **stack)
{
	t_node *temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node *temp;
											//  TEMP -> head(A) -> 1
	temp = stack_a->head;					//	 1 ->  2 ->  3 ->  4 ->  5 -> NULL 
	stack_a->head = stack_a->head->next;	//	head ->  2 ->  3 ->  4 ->  5 -> NULL 
	push_to_stack(&stack_b->head, temp);	//  head (B) -> 1
}


void push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node *temp;

	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	push_to_stack(&stack_a->head, temp);
}