/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:26:02 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/07 12:44:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	push_to_stack(t_node **stack, t_node *new_node)
{							 //  head = NULL				head(B) -> NULL
	new_node->next = *stack; //   5 -> NULL					TEMP(1) -> head(B) = NULL
	*stack = new_node;       //   head -> 5 -> NULL			head(TEMP) -> 1 -> NULL
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)  
					//chamada: por push_swap.c:  print_stacks(&stacks.stack_a, &stacks.stack_b)
{
	t_node	*node_a;			// ponteiro tipo t_node de nome node_a;
	t_node	*node_b;			// ponteiro tipo t_node de nome node_b;
	int		diff;				// variavel diff (Para receber a dirença entre node_a e node_b)

	if (!stack_b->head)			// Se (Não tiver stack_b)
	{
		print_stack_a(stack_a); // Printa a stack_a
		printf("-----	-----\n");
		printf("  A	  B \n");
		return ;
	}
	else if (!stack_a->head)	// Senao Se (Não tiver a stack_a)
	{
		print_stack_b(stack_b); // Printa a stack_b
		printf("-----	-----\n");
		printf("  A	  B \n");
		return ;
	}
	diff = stack_size(*stack_a) - stack_size(*stack_b); // diff recebe (stack_a - stack_b)
		// Aqui é usado node_a e node_b para percorrer as stack sem modifica-las e perder informações
	node_a = stack_a->head;				// node_a aponta para o nó que head aponta da stack_a
	node_b = stack_b->head;				// node_b aponta para o nó que head aponta da stack_b
	while (node_a->next != NULL)		// Enquanto (campo next de node_a for diferente de Null)
	{
		if (diff < 0)					// Se a diferenca for menor que zero
		{									 // significa que stack_a é menor que stack_b	
			printf("	");				// imprime
			diff++;						// incrementa afim que diff exita mais
		}
		else							//Senao
		{
			printf("%d	", node_a->data); // Imprime o valor do node_a
			node_a = node_a->next;		  // avança para o proximo nó;
		}
		if (node_b->next != NULL)		  // Se o campo next for diferente de NULL
		{
			if (diff > 0)				  // Se a diferenca for menor que zero
			{									// significa que stack_a é maior que stack_b
				printf("\n");
				diff--;						// decrementa afim que diff exita mais
		
			}
			else							// Senao
			{
				printf("%d\n", node_b->data);	// imprime( valor do nó B)
				node_b = node_b->next;			// anda para o proximo nó
			}
		}
		else							  // Senao	
			printf("%d\n", node_b->data); // Imprime (valor do nó B)
	}
	printf("%d	", node_a->data);	// Imprime (valor do nó A)
	printf("%d\n", node_b->data);	// Imprime (valor do nó B)
	printf("-----	");
	printf("-----\n");
	printf("A	B\n");
}

void print_stack_a(t_stack *stack_a)
{
	t_node *temp;
	
	temp = stack_a->head;
		while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void print_stack_b(t_stack *stack_b)
{
	t_node *temp;
	
	temp = stack_b->head;
	while (temp != NULL)
	{
		printf("	%d\n", temp->data);
		temp = temp->next;
	}
}

t_node *get_bottom_element(t_node *stack)
{
	if (stack == NULL)
		return (0);						
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int stack_size(t_stack stack)
{
	stack.size = 0;
	while (stack.head->next != NULL)
	{
		stack.size++;
		stack.head = stack.head->next;
	}
	stack.size++;
	return (stack.size);
}


void	append_to_stack(t_node **stack, t_node *new)
{
	t_node	*last;

	last = get_bottom_element(*stack);
	if (last != NULL)
		last->next = new;
	else
		*stack = new;
}

void	min_max(t_stack *stack_a)
{	
	t_node *temp;
	
	temp = stack_a->head;
	stack_a->min = temp->data;
	stack_a->max = temp->data;
	while (temp != NULL)
	{	
		if(temp->data < stack_a->min)
			stack_a->min = temp->data;
        if(temp->data > stack_a->max)
			stack_a->max = temp->data;
        temp = temp->next;
	}
	printf("\nMenor: %d\n", stack_a->min);
    printf("Maior: %d\n", stack_a->max);

}
