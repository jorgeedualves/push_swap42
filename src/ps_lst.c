/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:57 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/11 16:46:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*list_new(char *array_index_bin, int array_index)
{
	t_stack		*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		exit(EXIT_FAILURE);
	node->index_bin = array_index_bin;
	node->index = array_index;
	node->next = NULL;
	return (node);
}

t_stack	*list_last(t_stack *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	list_add_back(t_stack **lst, t_stack *next)
{
	t_stack	*last;

	last = list_last(*lst);
	if (last != 0)
		last->next = next;
	else
		*lst = next;
}
