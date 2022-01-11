/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:25:31 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/11 00:22:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_limit(int len_argc)
{
	int	limit;

	limit = 0;
	while ((len_argc / 2) != 0)
	{
		limit++;
		len_argc = len_argc / 2;
	}
	return (limit);
}

char	*ft_itob(int len_argc, int index)
{
	int		digit;
	int		i;
	char	*str_bin;
	int		limit;

	limit = find_limit(len_argc);
	i = 0;
	str_bin = (char *)malloc((sizeof(char *) * limit) + 1);
	if (str_bin == NULL)
		exit(EXIT_FAILURE);
	while (limit >= 0)
	{
		digit = index >> limit;
		if (digit & 1)
			*(str_bin + i) = 1 + '0';
		else
			*(str_bin + i) = 0 + '0';
		i++;
		limit--;
	}
	*(str_bin + i) = '\0';
	return (str_bin);
}

char	**string_bin(int argc, int *index)
{
	int		i;
	char	**string_bin;

	string_bin = (char **)malloc((sizeof(char **) * argc) + 1);
	if (string_bin == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc)
	{
		string_bin[i] = ft_itob(argc, index[i]);
		i++;
	}
	return (string_bin);
}
