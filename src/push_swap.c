/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:23 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/24 17:10:22 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*int	main(int argc, char const **argv)
{
	t_list stack_a;
	t_list new_node;
	int 	i;
	int		j;

	i = 0;
	j = 1;
	
	if(agc == 2)
		stack_a->content = ft_lstnew(*argv);
	while (*argv)
	{
		if (j > 1)
			stack_a->content = ft_lstadd_back(**argv, new_node);
		argv++;
		j++;
	}
	while (*stack)
	{
		printf("%c ", *stack);
		stack++;
	}
	printf("\n");
	return (0);
}
*/
void print_stack(t_list *stack)
{
	t_list *node;

	node = stack;
	while (node->next != NULL)
	{
		printf("%d\n", node->content);
		node = node->next;
	}
	printf("%d\n", node->content);
}

int main(int argc, char **argv)
{
	t_list *stack = NULL;
	t_list *node = NULL;
	int i;

	i = 0;
	if (argc >= 2)
	{
		while (argv[i])
			i++;
		while (argv[--i])
		{
			node = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&stack, node);
			if (i == 1)
				break ;
		}
		print_stack(stack);
	}
	else
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putstr_fd("	Too few arguments provided!", 1);
	}
	return (0);
}