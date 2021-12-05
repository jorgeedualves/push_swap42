/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:26:02 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/05 18:05:22 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	push_to_stack(t_node **stack, t_node *new_node)
{							 //  head = NULL				head(B) -> NULL
	new_node->next = *stack; //   5 -> NULL					TEMP(1) -> head(B) = NULL
	*stack = new_node;       //   head -> 5 -> NULL			head(TEMP) -> 1 -> NULL
}

void	print_stack(t_node *stack)
{
	t_node	*node;

	node = stack;
	while (node->next != NULL)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}

t_node	*get_bottom_element(t_node *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	append_to_stack(t_node **stack, t_node *new)
{
	t_node	*last;

	last = get_bottom_element(*stack);
	if (last != NULL)
		last->next = new;
	else
		*stack = new;
}
