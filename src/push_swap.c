/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:21 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/10 20:23:24 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*num;
	int			*index;
	char		**bin;

	argc--;
	argv++;
	num = malloc(sizeof(int) * argc);
	if(!num)
		exit(EXIT_FAILURE);
	validate_args(argc, argv);
	transform_args(argc, argv, num);
	check_duplicates(argc, num);
	if (array_is_sorted(argc, num))
		exit(EXIT_SUCCESS);
	else
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putstr_fd("	Too few arguments provided!", 1);
	}
	index = link_index(argc, num);
	bin = string_bin(argc, index);
	init_struct(&stacks, argc);
	fill_stack_a(&stacks, bin, index);
	// push_swap(&stacks, index);
	// freeing(&stacks, num, index, bin);

	// printf("---------------------------\n");	
//	print_stacks(stacks.stack_a, stacks.stack_b);
	//sort_stacks(&stacks);
	//min_max(&stacks.stack_a);
	return (0);
}

void	init_struct(t_stacks *stack, int argc)
{
	

	stack->stack_a->head = NULL;
	stack->stack_b->head = NULL;
	stack->stack_a->size = argc;
	
}

void	fill_stack_a(t_stacks *stacks, char **bin, int *index)
{
	int i;

	if(stacks->stack_a->size)
	{
		i = 0;
		stacks->stack_a = ps_lstnew(bin[i], index[i]);
		while (i < stacks->stack_a->size -1)
		{
			i++;
			ps_lstadd_back(&stacks->stack_a, ps_lstnew(bin[i], index[i]));
		}
	}
}
/*
void push_swap (t_stacks *stacks, int *index)
{
	if(stacks->stack_a->size <= 5)
		short_push_swap(stacks, index);
	else
		long_push_swap(stacks);
}
*/