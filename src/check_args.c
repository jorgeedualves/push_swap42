/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:24 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/10 23:47:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (is_integer(argv[i]) == 0)
		{
			exit_error();
			return (-1);
		}
		i++;
	}
	return (0);
}

void	check_duplicates(int argc, int *array_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (array_num[i] == array_num[j])
				exit_error();
			j++;
		}
		i++;
	}
}

void	transform_args(int argc, char **argv, int *array_num)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		array_num[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	array_is_sorted(int len, int *array_num)
{
	int	i;

	i = 0;
	while (i < len - 1 && array_num[i] < array_num[i + 1])
		i++;
	if (i == len - 1)
	{
		exit(EXIT_SUCCESS);
	}
}
