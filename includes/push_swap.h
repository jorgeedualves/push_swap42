/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:49:46 by joeduard          #+#    #+#             */
/*   Updated: 2021/12/14 04:57:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	char			*data;
	struct s_stack	*next;
	int				index;

}t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		limit;
	int		len;
}t_stacks;

int		validate_args(int argc, char **argv);
int		is_integer(char *argv);
void	check_duplicates(int argc, int *num);
void	array_is_sorted(int argc, int *num);
void	transform_args(int argc, char **argv, int *num);

void	init_struct(t_stacks *stacks, int argc);
void	fill_stack_a(t_stacks *stacks, char **bin, int *index);

t_stack	*ps_lstnew(char *bin, int index);
void	ps_lstadd_back(t_stack **lst, t_stack *next);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstdelone(t_stack *lst, void (*del)(void *));
t_stack	*ps_lstprevlast(t_stack *lst);
void	ps_lstadd_front(t_stack **lst, t_stack *new);

void	ps_lstclear(t_stack **lst);
void	freeing(t_stacks *stacks, int *num, int *index, char **bin);
void	exit_error(void);

void	ft_del(int *content);

char	*ft_itob(int len, int num);
char	**string_bin(int len, int *num);
int		find_limit(int len);

// Push_Swap Actions
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);
void	swap(t_stacks *stack);
void	rotate(t_stacks *stack);
void	reverse_rotate(t_stacks *stack);

int		*quick_sort(int len, int *num);
int		*get_index(int len, int *num, int *cpy);
int		*link_index(int len, int *num);

void	push_swap(t_stacks *stacks, int *index);
void	short_push_swap(t_stacks *stacks, int *index);
void	long_push_swap(t_stacks *stacks);

#endif