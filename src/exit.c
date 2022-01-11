/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:20:44 by joeduard          #+#    #+#             */
/*   Updated: 2022/01/11 12:16:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	freeing(t_stacks *stacks, int *num, int *index, char **bin)
{
	int	i;

	free(index);
	index = NULL;
	free(num);
	num = NULL;
	ps_listclear (&stacks->stack_a);
	ps_listclear (&stacks->stack_b);
	i = 0;
	while (i < stacks->len)
	{
		free(bin[i]);
		i++;
	}
	free(bin);
}

void	ps_listclear(t_stack **lst)
{
	t_stack	*aux;
	t_stack	*temp;

	temp = NULL;
	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
