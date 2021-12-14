/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:39:47 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 04:39:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_is_digit(char *argv)
{
	if (argv[0] == '-' && !ft_isdigit(argv[1]))
		return (-1);
	if (argv[0] == '-' && argv[1] == '\0')
		return (-1);
	if (argv[0] != '-' && !ft_isdigit(argv[0]))
		return (-1);
	if (argv[0] == '\0')
		return (-1);
	return (0);
}

static int	check_is_negative(char *argv, int *negative, int i)
{
	if (argv[i] == '-')
	{
		*negative = 1;
		i++;
	}
	else
		*negative = -1;
	return (i);
}

int	is_integer(char *argv)
{
	int		i;
	long	num;
	int		negative;

	if (!check_is_digit(argv))
		return (-1);
	i = check_is_negative (argv, &negative, 0);
	num = 0;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (-1);
		num = num * 10 + argv[i] - '0';
		if (negative == 1 && - num < INT_MIN)
			return (-1);
		if (negative == -1 && num > INT_MAX)
			return (-1);
		i++;
	}
	return (1);
}
