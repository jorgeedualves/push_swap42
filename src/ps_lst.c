/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:57 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/11 00:10:44 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ps_lstnew(char *array_index_bin, int array_index)
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

t_stack	*ps_lstlast(t_stack *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *next)
{
	t_stack	*last;

	last = ps_lstlast(*lst);
	if (last != 0)
		last->next = next;
	else
		*lst = next;
}
