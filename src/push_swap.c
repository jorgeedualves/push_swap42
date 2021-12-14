/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:21 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 19:17:31 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*num;
	int			*index;
	char		**bin;

	if (argc == 1)
		exit(0);
	argc--;
	argv++;
	num = malloc(sizeof(int) * argc);
	if (!num)
		exit_error();
	validate_args(argc, argv);
	transform_args(argc, argv, num);
	check_duplicates(argc, num);
	array_is_sorted(argc, num);
	index = link_index(argc, num);
	bin = string_bin(argc, index);
	init_struct(&stacks, argc);
	fill_stack_a(&stacks, bin, index);
	push_swap(&stacks, index);
	freeing(&stacks, num, index, bin);
	return (0);
}

void	init_struct(t_stacks *stack, int argc)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len = argc;
}

void	fill_stack_a(t_stacks *stacks, char **bin, int *index)
{
	int	i;

	if (stacks->len)
	{
		i = 0;
		stacks->stack_a = ps_lstnew(bin[i], index[i]);
		while (i < stacks->len - 1)
		{
			i++;
			ps_lstadd_back(&stacks->stack_a, ps_lstnew(bin[i], index[i]));
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
