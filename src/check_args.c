/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:24 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/10 20:21:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
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

void	check_duplicates(int argc, int *num)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (num[i] == num[j])
			{
				ft_putstr_fd("	INPUT WITH DUPLICATION!\n", 1);
				exit_error();
			}
			j++;
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}

void	transform_args(int argc, char **argv, int *num)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		num[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	array_is_sorted(int len, int *num)  // colocar esse codigo
{
	int	i;

	i = 0;
	while (i < len - 1 && num[i] < num[i + 1])
		i++;
	if (i == len - 1)
	{
		ft_putstr_fd("	STACK IS ORDERED!\n", 1);
		return(0);
	}
	else
		return(-1);
}
