/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:57 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/10 20:21:59 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ps_lstnew(char *bin, int index)
{
	t_stack		*node;
    node = (t_stack *)malloc(sizeof(t_stack));
	if(node->head == NULL)
	{
		exit(EXIT_FAILURE);
	}
	node->head->data = bin;
	node->head->index = index;
	node->head->next = NULL;
	return (node);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (lst == 0)
		return (0);
	while (lst->head->next != 0)
		lst = lst->head->next;
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *next)
{
	t_stack	*last;

	last = ps_lstlast(*lst);
	if (last != 0)
		last->head->next = next;
	else
		*lst = next;
}

t_stack	*ps_lstprevlast(t_stack *lst)
{
	if (lst == 0)
		return (0);
	while (lst->head->next->next != 0)
		lst = lst->head->next->next;
	return (lst);
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	new->head->data = *lst;
	*lst = new;
}