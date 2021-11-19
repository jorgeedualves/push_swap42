/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/19 19:33:02 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void	insertion_sort(char *stack_a)
{	
	int		i;
	int		value;
	int		*stack_b;
	int		stack_size;

	stack_size = malloc ((int) sizeof (stack_a));
	i = 1;
	while (i < stack_size - 1)
	{		
		value = stack_a[i];
		*stack_b = i;
		while (stack_b > 0 && stack_a[*stack_b - 1] > value)
		{
			stack_a[*stack_b] = stack_a[*stack_b - 1];
			stack_b = stack_b - 1;
		}
		i++;
	}
	printf("Lista ordenada: %d\n", *stack_a);
}
*/
int	main(int argc, char const **argv)
{
	char	*stack;
	int 	i;
	int		j;

	i = 0;
	j = 1;
	stack = (char *)malloc((strlen(*argv) - 1) * sizeof(char));
	if (argc < 2)
		printf("Número invalido de argumentos!\n");
		return (EXIT_FAILURE);
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
	printf("\n");
	return (0);
}
