/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/09 15:44:51 by joeduard         ###   ########.fr       */
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
			stacks.stack_a.size++;
			if (i == 1)
				break ;	
		}
		
		  // do print_actions:
		// do_print_pa(&stacks);
		// do_print_pb(&stacks);
		// do_print_ra(&stacks);
		// do_print_rb(&stacks);
		// do_print_rr(&stacks);
		// do_print_rra(&stacks);
		// do_print_rrb(&stacks);
		// do_print_rrr(&stacks);
		
		 // actions:
		// rotate(&stacks.stack_a->head);
		// reverse_rotate(&stacks.stack_a->head);
		// push_a(&(*stacks.stack_a), &(*stacks.stack_b));
		// push_b(&(*stacks.stack_a), &(*stacks.stack_b));
		// swap(&stacks.stack_a->head);

		printf("---------------------------\n");
		print_stacks(&stacks.stack_a, &stacks.stack_b);
		sort_stacks(&stacks);
		min_max(&stacks.stack_a);
		print_stacks(&stacks.stack_a, &stacks.stack_b);	
	}
	else
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putstr_fd("	Too few arguments provided!", 1);
	}
	return (0);
}
