/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:49:49 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/03 18:13:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stacks *stacks)
{
	
	if (stacks->stack_a->head->data > stacks->stack_a->head->next->data)
		do_print_sa(stacks);
		else
	return ;
}

void	sort_three(t_stacks *stacks)
{
	int first;
	int second;
	int third;

	first = stacks->stack_a->head->data;
	second = stacks->stack_a->head->next->data;
	third = stacks->stack_a->head->next->next->data;

	if (first > second && second > third && first > third)
	{
		do_print_sa(stacks);
		do_print_rra(stacks);
	}
	else if (first < second && second > third && first < third)
	{
		do_print_rra(stacks);
		do_print_sa(stacks);
	}
	else if (first > second && second < third && first < third)
		do_print_sa(stacks);
	else if (first < second && second > third && first > third)
		do_print_rra(stacks);
	else if (first > second && second < third && first > third)
		do_print_ra(stacks);
	else if (first < second && second < third)
		return ;
}

void    sort_five(t_stacks *stacks)
{
    while (stacks->stack_a->size > 3)
        do_print_pb(stacks);
    sort_three(stacks);
    sort_two(stacks);
    write(1, "sb\n", 3);
    do_print_pa(stacks);
    do_print_pa(stacks);

}
  
        //     stack_a                     stack_b
        // início  pb pb sort_three        sort_two pa pa
        //     1                
        //     5   5             X   nada | sa |    | ra
        //     2   2   2   2     2  
        //     4   4   4   3     3           5  1
        //     3   3   3   4     4           1  5        
            
        //     se 5 >

        //     5 -> 2 -> 3 -> 4 

void	sort_stack(t_stacks *stacks)
{
	if (stacks->stack_a->size == 1)
		return;
	if (stacks->stack_a->size == 2)
		sort_two(stacks);
	if (stacks->stack_a->size == 3)
		sort_three(stacks);
	// if (stack->stack_a.size > 3 && stack->stack_a.size < 6)
	//     sort_five(stack);

}