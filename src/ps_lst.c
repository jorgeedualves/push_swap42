/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:57 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/13 18:32:06 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ps_lstnew(char *bin, int index)
{
	printf("\nFUNÇAO PS LSTNEW\n");
	t_stack		*node;
    node = (t_stack *)malloc(sizeof(t_stack));
	if(node == NULL)
	{
		printf("\nFUNÇAO LSTNEW DEU RUIM NO MALLOC\n");
		exit(EXIT_FAILURE);
	}
	printf("\nFUNÇAO LSTNEW ANTES DE ATRIBUIR BIN E INDEX\n");
	node->head->data = bin;
	printf("\natribuiu para o bin\n");
	node->head->index = index;
	printf("\natribuiu para o index\n");
	node->head->next = NULL;
	printf("\natribuiu para o next\n");
	printf("\nFUNÇAO lstnew retorno\n");
	return (node);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	printf("\nFUNÇAO PS_LSTLAST\n");
	if (lst == 0)
		return (0);
	while (lst->head->next != 0)
		lst->head = lst->head->next;
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *next)
{
	t_stack	*last;

	printf("\nFUNÇAO PS_LSTADD\n");

	last = ps_lstlast(*lst);
	if (last != 0)
		last = next;
	else
		*lst = next;
}

t_stack	*ps_lstprevlast(t_stack *lst)
{
	printf("\nFUNÇAO PS_LSTPREVLAST\n");
	if (lst == 0)
		return (0);
	while (lst->head->next->next != 0)
		lst->head = lst->head->next->next;
	return (lst);
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	printf("\nFUNÇAO LSTADD_FRONT\n");
	new = *lst;
	*lst = new;
}