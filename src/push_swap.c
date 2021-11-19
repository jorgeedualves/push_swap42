/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/18 21:18:44 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void insertion_sort  (char *array)
{	
	int	i;
	int	*temp;
	int	value;
	int stack_size;

	stack_size = malloc((int)sizeof(array));

	i = 1;
	while (i < 0)
	{		
		value = array[i];
		*temp = i;		
		while (temp > 0 && array[*temp - 1] > value)
		{
			array[*temp] = array[*temp - 1];
			temp = temp - 1;
		}
		i++;
	}
}

int main    (int argc, char *argv[])
{
	int stack_size;

	if(argc != 2)
		return(-1);
	insertion_sort(argv[1]);
	return (0);
}