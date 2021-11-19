/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/19 12:42:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	insertion_sort(char *array)
{	
	int		i;
	int		value;
	char	*stack_b;
	char	*stack_a;
	int		stack_size;

	stack_a = array;
	stack_size = malloc ((int) sizeof (array));
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
}

int	main(int argc, char *argv[])
{
	int	stack_size;

	if (argc != 2)
		return (-1);
	printf("stack %s", *argv[1]);
	insertion_sort(argv[1]);
	return (0);
}
