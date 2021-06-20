/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:49:52 by lbrandy           #+#    #+#             */
/*   Updated: 2021/06/20 15:54:18 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_num
{
	int		numeric;
	int		index;
	int		keep_in_stack_a;
}				t_num;

typedef struct	s_stacks
{
	t_num	*stack_a;
	t_num	*stack_b;
}				t_stacks;
