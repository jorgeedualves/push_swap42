/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/22 18:16:02 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
void	insertion_sort(char *stack, int *stack_size)
{								

	int i;
	int value;
	int hole;

	i = 1;
								
	while(i < *stack_size - 1)							
	{							
		value = stack[i];						
		hole = i;												
		while(hole > 0 && stack[hole - 1] > value)						
		{						
			stack[hole] = stack[hole - 1];					
			hole = hole - 1;					
		}						
		i++;						
	}
	printf("Lista ordenada: %s", *stack);							
}								
*/								
int	main(int argc, char const **argv)
{
	char	*stack;
	int 	i;
	int		j;
	int		stack_size;

	i = 0;
	j = 1;
	stack = (char *)malloc((strlen(*argv) - 1) * sizeof(char));
	stack_size = strlen(stack);
	if (argc < 2)
	{
		printf("Número invalido de argumentos!\n");
		return (EXIT_FAILURE);
	}
	while (*argv)
	{
		if (j > 1)
			stack[i++] = **argv;
		argv++;
		j++;
	}
	while (*stack)
	{
		printf("%c ", *stack);
		stack++;
	}
	printf("\nStack Size: %d \n", stack_size);
	printf("\n");
	return (0);
}