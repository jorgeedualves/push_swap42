/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:25:31 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 05:07:05 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_limit(int len)
{
	int	limit;

	limit = 0;
	while ((len / 2) != 0)
	{
		limit++;
		len = len / 2;
	}
	return (limit);
}

char	*ft_itob(int len, int num)
{
	int		limit_cont;
	int		digit;
	int		i;
	char	*pointer;
	int		limit;

	limit = find_limit(len);
	i = 0;
	pointer = (char *)malloc((sizeof(char *) * limit) + 1);
	if (pointer == NULL)
		exit(EXIT_FAILURE);
	limit_cont = limit;
	while (limit_cont >= 0)
	{
		digit = num >> limit_cont;
		if (digit & 1)
			*(pointer + i) = 1 + '0';
		else
			*(pointer + i) = 0 + '0';
		i++;
		limit_cont--;
	}
	*(pointer + i) = '\0';
	return (pointer);
}

char	**string_bin(int len, int *num)
{
	int		i;
	char	**string_bin;

	string_bin = (char **)malloc((sizeof(char **) * len) + 1);
	if (string_bin == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < len)
	{
		string_bin[i] = ft_itob(len, num[i]);
		i++;
	}
	return (string_bin);
}
