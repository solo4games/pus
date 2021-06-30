/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:47:58 by lbrandy           #+#    #+#             */
/*   Updated: 2021/06/30 15:57:55 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int check_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

int check_errors(char *str[], int num)
{
	int i;

	i = 1;
	if (num == 1)
		return (0);
	while (i < num)
	{
		if (!check_number(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_repeats(int numeric, int mass[], int limit)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (i < limit)
	{
		if (numeric == mass[i])
			counter++;
		if (counter > 1)
			return (0);
		i++;
	}
	return (1);
}

int	fill_stack(t_stacks *stacks, char *str[], int num)
{
	int mass[num];
	int numeric;

	stacks->top_b = 0;
	while (stacks->top_b < num - 1)
	{
		numeric = ft_atoi(str[stacks->top_b + 1]);
		mass[stacks->top_b] = numeric;
		if (check_repeats(numeric, mass, stacks->top_b + 1) == 0)
			return (0);
		stacks->stack_b[stacks->top_b].numeric = numeric;
		stacks->top_b++;
	}
	return (1);
}

int		find_min(t_num *stack_b, int num)
{
	int min;
	int i;

	i = 0;
	while (stack_b[i].index != -1)
		i++;
	min = stack_b[i].numeric;
	while (i < num - 1)
	{
		if (stack_b[i].numeric < min && stack_b[i].index == -1)
			min = stack_b[i].numeric;
		i++;
	}
	return (min);
}

void	init_indexes(t_num *stack_b, int num)
{
	int i;

	i = 0;
	while (i < num - 1)
	{
		stack_b[i].index = -1;
		i++;
	}
}

void	indexing(t_num *stack_b, int num)
{
	int i;
	int min;
	int j;

	j = 0;
	init_indexes(stack_b, num);
	while (j < num - 1)
	{
		min = find_min(stack_b, num);
		i = 0;
		while (stack_b[i].numeric != min)
			i++;
		stack_b[i].index = j;
		j++;
	}
}

void	start(t_stacks *stacks, int num)
{
	stacks->top_a = 0;
	stacks->stack_a = (t_num *)malloc(sizeof(t_num) * num);
	while (stacks->top_b > 0)
		pa(stacks);
	markup_index(stacks->stack_a, stacks->top_a);
}

int main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (check_errors(argv, argc) == 0)
		return (2);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (2);
	stacks->stack_b = (t_num *)malloc(sizeof(t_num) * argc);
	if (!stacks->stack_b)
		return (2);
	if (fill_stack(stacks, argv, argc) == 0)
		return (2);
	int i = argc - 2;
	indexing(stacks->stack_b, argc);
	start(stacks, argc);
	while (i >= 0)
	{
		printf("%d				%d				%d\n", 
				stacks->stack_a[i].numeric, stacks->stack_a[i].index, stacks->stack_a[i].keep_in_stack);
		i--;
	}
	printf("top_a - %d, top_b - %d\n", stacks->top_a, stacks->top_b);
	return (0);
}
