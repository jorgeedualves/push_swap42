/*
		OPERAÇÕES DA PILHA

  //	Novo Nó (Valor)
t_node *new_node(int data)				    // por push_swap.c:   new_node(ft_atoi(argv[i]));
{
	t_node *node;							// ponteiro tipo t_node de nome node;

	node = (t_node *)malloc(sizeof(t_node)); // Alocaçao de memória do tamanho da struct t_node
	node->data = data;						 // campo data recebe o valor
	node->next = NULL;						 // campo next recebe  NULL;
	return (node);
}
*/
#include "../includes/push_swap.h"
	// Envia para Pilha
void push_to_stack(t_node **stack, t_node *new_node)  // chamada por action: push_to_stack(stack, last)
													  // chamada por action: push_to_stack(&stack_b->head, temp);
													  // chamada por action: push_to_stack(&stack_a->head, temp);		
{									//   head = NULL				head(B) -> NULL
	new_node->next = *stack;		//   5 -> NULL					TEMP(1) -> head(B) = NULL
	*stack = new_node;				//   head -> 5 -> NULL			head(TEMP) -> 1 -> NULL
}

//			Printa pilhas 
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
			printf("%s	", node_a->data); // Imprime o valor do node_a
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
				printf("%s\n", node_b->data);	// imprime( valor do nó B)
				node_b = node_b->next;			// anda para o proximo nó
			}
		}
		else							  // Senao	
			printf("%s\n", node_b->data); // Imprime (valor do nó B)
	}
	printf("%s	", node_a->data);	// Imprime (valor do nó A)
	printf("%s\n", node_b->data);	// Imprime (valor do nó B)
	printf("-----	");
	printf("-----\n");
	printf("A	B\n");
}

		// imprime a stack_a
void print_stack_a(t_stack *stack_a)		  //  chamada:   print_stack_a(stack_a)
{
	t_node *temp;
	
	temp = stack_a->head;
		while (temp != NULL) // Enquanto o proximo nó depois de headfor diferente de NULL
	{
		printf("%s\n", temp->data); // imprime o valor do nó que head aponta
		temp = temp->next;   		// avança para o próximo nó
	}
}

	// imprime a stack_b
void print_stack_b(t_stack *stack_b)			// chamada:   print_stack_b(stack_b)
{
	t_node *temp;
	
	temp = stack_b->head;
	while (temp != NULL)						// Enquanto o proximo nó depois de head for diferente de NULL
	{
		printf("	%s\n", temp->data); // imprime o valor do nó que head aponta
		temp = temp->next;	   					// avança para o próximo nó
	}
}

 	// Obter o último elemento da stack 
t_node *get_bottom_element(t_node *stack)   // chamada: get_bottom_element(*stack)
{
	if (stack == NULL)				// Se não tiver stack
		return (0);						
									// Enquanto o campo next for diferente de NULL
	while (stack->next != NULL)		//	2 -> 3 -> 4 -> 5 -> NULL  
		stack = stack->next;		//	->    ->    ->	  5		  Avança nos nós da stack
	return (stack);					// (5)   Retorna o último nó da stack
}

	// Tamanho da Stack
int stack_size(t_stack stack)		// chamada: stack_size(*stack_a)			
{
	stack.size = 0;						// inicializa o tamanho com zero;
	while (stack.head->next != NULL)	// enquanto a stack for diferente de NULL
	{
		stack.size++;					// incrementa o tamanho em 1
		stack.head = stack.head->next;  // avança na stack
	}
	stack.size++;						// incrementa o tamanho em 1	
	return (stack.size);				// retorna (valor do tamanho)
}

	// Anexar  á pilha (2-> 3-> 4-> 5-> NULL  ,   1)
void	append_to_stack(t_node **stack, t_node *new) //   chamada append_to_stack(&(*stack), temp);
{
	t_node	*last;						// ponteiro do tipo t_node de nome last

	last = get_bottom_element(*stack);	//	last = 5;  last recebe último nó da stack
	if (last != NULL)					// Se tiver valor em last 
		last->next = new;				// 5 -> 1;		// o nó last aponta para o (new) novo nó
	else								// Senao
		*stack = new;					// 1 ;	stack recebe o (new) novo nó
}
