/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/29 23:10:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;
	// t_stack	*stack_b = NULL;
	t_node	*node = NULL;
	// stack_a.head = NULL;
	int i;

	i = 0;

	// Se está ordenada
	// Se existem duplicatas
	// limpar a stack
	ft_bzero(&stacks, sizeof(t_stacks));
	if (argc >= 2)
	{
		while (argv[i])
			i++;
		while (argv[--i])
		{
			node = new_node(ft_atoi(argv[i]));
			push_to_stack(&stacks.stack_a.head, node);
			if (i == 1)
				break ;	
		}
		do_print_pb(&stacks);
		do_print_pb(&stacks);
		do_print_pb(&stacks);
		do_print_rrr(&stacks);
		printf("---------------------------\n");
		print_stack(stacks.stack_a.head);

		// printf("---------------------------\n");
		// push_a(&stacks.stack_a, &stacks.stack_b);
		// print_stack(stacks.stack_b.head);
		// print_stack(stacks.stack_b.head);
		// push(stack_a, stack_b);
		// print_stack(stack_a->head);
		// puts("\n");
		// print_stack(stack_b->head);
	}
	else
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putstr_fd("	Too few arguments provided!", 1);
	}

	return (0);
}
