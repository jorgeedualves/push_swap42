/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:24:19 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/10 23:59:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*cpy_vector(int argc, int *array_num)
{
	int	*array_cpy;
	int	i;

	array_cpy = malloc((sizeof(int) * argc) + 1);
	if (!array_cpy)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc)
	{
		array_cpy[i] = array_num[i];
		i++;
	}
	return (array_cpy);
}

int	*quick_sort(int argc, int *array_num)
{
	int	*array_cpy;
	int	aux;
	int	i;

	array_cpy = cpy_vector(argc, array_num);
	i = 0;
	while (i < argc - 1)
	{
		if (array_cpy[i] > array_cpy[i + 1])
		{
			aux = array_cpy[i];
			array_cpy[i] = array_cpy[i + 1];
			array_cpy[i + 1] = aux;
			i = -1;
		}
		i++;
	}
	return (array_cpy);
}

int	*get_index(int len, int *num, int *cpy)
{
	int	*array_index;
	int	i;
	int	j;

	array_index = cpy_vector(len, num);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (array_index[i] != cpy[j])
			j++;
		array_index[i] = j;
		i++;
	}
	return (array_index);
}

int	*link_index(int argc, int *array_num)
{
	int	*array_cpy;
	int	*array_index;

	array_cpy = quick_sort(argc, array_num);
	array_index = get_index(argc, array_num, array_cpy);
	free(array_cpy);
	return (array_index);
}
