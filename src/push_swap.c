/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:21 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/11 12:17:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*array_num;
	int			*array_index;
	char		**bin;

	if (argc == 1)
		exit(0);
	argc--;
	argv++;
	array_num = malloc(sizeof(int) * argc);
	if (!array_num)
		exit_error();
	validate_args(argc, argv);
	transform_args(argc, argv, array_num);
	check_duplicates(argc, array_num);
	array_is_sorted(argc, array_num);
	array_index = link_index(argc, array_num);
	bin = string_bin(argc, array_index);
	init_struct(&stacks, argc);
	fill_stack_a(&stacks, bin, array_index);
	push_swap(&stacks, array_index);
	freeing(&stacks, array_num, array_index, bin);
	return (0);
}

void	init_struct(t_stacks *stack, int argc)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len = argc;
}

void	fill_stack_a(t_stacks *stack, char **bin, int *index)
{
	int	i;

	if (stack->len)
	{
		i = 0;
		stack->stack_a = ps_listnew(bin[i], index[i]);
		while (i < stack->len - 1)
		{
			i++;
			ps_listadd_back(&stack->stack_a, ps_listnew(bin[i], index[i]));
		}
	}
}

void	push_swap(t_stacks *stacks, int *index)
{
	if (stacks->len <= 5)
		short_push_swap(stacks, index);
	else
		long_push_swap(stacks);
}
