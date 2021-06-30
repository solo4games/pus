/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:37:46 by lbrandy           #+#    #+#             */
/*   Updated: 2021/06/30 15:58:51 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	help(t_num *stack_a, int top_a, int i)
{
	int j;

	j = top_a - 1;
	while (j > i)
	{
		stack_a[j].keep_in_stack = 0;
		j--;
	}
}

int		index_count(t_num *stack_a, int top_a, int i)
{
	int counter;
	int index;

	counter = 0;
	help(stack_a, top_a, i);
	stack_a[i].keep_in_stack = 1;
	index = stack_a[i].index;
	counter++;
	i--;
	while (i >= 0)
	{
		if (stack_a[i].index == index + 1)
		{
			stack_a[i].keep_in_stack = 1;
			index++;
			counter++;
		}
		else
			stack_a[i].keep_in_stack = 0;
		i--;
	}
	return (counter);
}

void	markup_index(t_num *stack_a, int top_a)
{
	int max;
	int head_pos;
	int i;
	int temp;

	max = 0;
	i = top_a - 1;
	head_pos = 0;
	while (i >= 0)
	{
		temp = index_count(stack_a, top_a, i);
		if (temp == max)
			if (stack_a[i].index < stack_a[head_pos].index)
				head_pos = i;
		if (temp > max)
		{
			max = temp;
			head_pos = i;
		}
		i--;
	}
	index_count(stack_a, top_a, head_pos);
}
