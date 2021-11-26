/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:37:04 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/25 23:37:40 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_pos(char *curr_pos,
	char *next_pos, char curr_val, char next_val)
{
	*curr_pos = next_val;
	*next_pos = curr_val;
}
