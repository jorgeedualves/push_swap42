/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:57 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/13 19:01:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ps_lstnew(char *bin, int index)
{
	printf("\nFUNÇAO PS LSTNEW\n");
	t_node		*node;
    node = (t_node *)malloc(sizeof(t_node));
	if(node == NULL)
	{
		printf("\nFUNÇAO LSTNEW DEU RUIM NO MALLOC\n");
		exit(EXIT_FAILURE);
	}
	printf("\nFUNÇAO LSTNEW ANTES DE ATRIBUIR BIN E INDEX\n");
	node->data = bin;
	
	printf("\natribuiu para o bin\n");
	node->index = index;
	
	printf("\natribuiu para o index\n");
	node->next = NULL;
	
	printf("\natribuiu para o next\n");
	printf("\nFUNÇAO lstnew retorno\n");
	return (node);
}

t_node	*ps_lstlast(t_node *lst)
{
	printf("\nFUNÇAO PS_LSTLAST\n");
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_node **lst, t_node *next)
{
	t_node	*last;

	printf("\nFUNÇAO PS_LSTADD\n");

	last = ps_lstlast(*lst);
	if (last != 0)
		last->next = next;
	else
		*lst = next;
}

t_node	*ps_lstprevlast(t_node *lst)
{
	printf("\nFUNÇAO PS_LSTPREVLAST\n");
	if (lst == 0)
		return (0);
	while (lst->next->next != 0)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_front(t_node **lst, t_node *new)
{
	printf("\nFUNÇAO LSTADD_FRONT\n");
	new = *lst;
	*lst = new;
}