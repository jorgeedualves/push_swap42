/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:21 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/13 18:45:57 by joeduard         ###   ########.fr       */
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
	validate_args(argc, argv);			// ok
	transform_args(argc, argv, num);	// ok
	check_duplicates(argc, num);		// ok
	array_is_sorted(argc, num);			// ok
	
	printf("\nANTES DO INDEX\n");
	index = link_index(argc, num);		// ok
	printf("\nDEPOIS DO INDEX\n");
	
	printf("\nANTES DO BIN\n");
	bin = string_bin(argc, index);		// ok
	printf("\nDEPOIS DO BIN\n");
	
	printf("\nANTES DA INIT_STRUCT\n");
	init_struct(&stacks, argc);			
	printf("\nDEPOIS DA INIT_STRUCT\n");

	printf("\nANTES DA FILL STACK A\n");
	fill_stack_a(&stacks, bin, index);		// ok
	printf("\nDEPOIS DA FILL STACK A\n");
	
	printf("\nANTES DA PUSH SWAP\n");
	push_swap(&stacks, index);
	printf("\nDEPOIS DA PUSH SWAP\n");
	
	freeing(&stacks, num, index, bin);

	 printf("---------------------------\n");	
//	print_stacks(stacks.stack_a, stacks.stack_b);
//	sort_stacks(&stacks);

	return (0);
}

void	init_struct(t_stacks *stack, int argc)
{
	printf("\nFUNÇAO INIT STRUCT\n");
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len = argc;	
}

void	fill_stack_a(t_stacks *stacks, char **bin, int *index)
{
	int i;
	printf("\nFUNÇAO FILL STACK A\n");
	if(stacks->len)
	{
		i = 0;
		stacks->stack_a = ps_lstnew(bin[i], index[i]);
		printf("\nANTES DO WHILE\n");
		while (i < stacks->len - 1)
		{
			i++;
			printf("\nENTRA EM ADD BACK\n");
			ps_lstadd_back(&stacks->stack_a, ps_lstnew(bin[i], index[i]));
		}
	}
}

void push_swap (t_stacks *stacks, int *index)
{
	printf("\nFUNÇAO PUSH_SWAP\n");
	if(stacks->stack_a->size <= 5)
		short_push_swap(stacks, index);
	else
		long_push_swap(stacks);
}
