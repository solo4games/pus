/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:49:52 by lbrandy           #+#    #+#             */
/*   Updated: 2021/06/30 17:44:04 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

typedef struct	s_num
{
	int		numeric;
	int		index;
	int		keep_in_stack;
}				t_num;

typedef struct	s_stacks
{
	t_num	*stack_a;
	t_num	*stack_b;
	int		top_a;
	int		top_b;
}				t_stacks;

void	sa(t_num *stack_a, int top_a);
void	pa(t_stacks *stacks);
void	ra(t_num *stack_a, int top_a);
void	rra(t_num *stack_a, int top_a);
void	sb(t_num *stack_b, int top_b);
void	pb(t_stacks* stacks);
void	rb(t_num *stack_b, int top_b);
void	rrb(t_num *stack_b, int top_b);
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);
int		greater_count(t_num *stack_a, int top_a, int i);
int		markup_greater(t_num *stack_a, int top_a);
void	markup_index(t_num *stack_a, int top_a);
int		index_count(t_num *stack_a, int top_a, int i);

#endif
