/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:39:47 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/13 12:21:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_is_digit(char *argv)
{
	if (argv[0] == '-' && !ft_isdigit(argv[1]))
		return (false);
	if (argv[0] == '-' && argv[1] == '\0')
		return (false);
	if (argv[0] != '-' && !ft_isdigit(argv[0]))
		return (false);
	if (argv[0] == '\0')
		return (false);
	return (true);
}

static int	check_is_negative(char *argv, bool *negative, int i)
{
	if (argv[i] == '-')
	{
		*negative = true;
		i++;
	}
	else
		*negative = false;
	return (i);
}

int is_integer(char *argv)
{
	int		i;
	long	num;
	bool	negative;

	if(!check_is_digit(argv))
		return (false);
	i = check_is_negative (argv, &negative, 0);
	num = 0;
	while (argv[i] != '\0')
	{
		if(!ft_isdigit(argv[i]))
			return (false);
		num = num * 10 + argv[i] - '0';
		if (negative == true && - num < INT_MIN)
			return (false);
		if (negative == false && num > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}
