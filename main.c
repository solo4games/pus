/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:47:58 by lbrandy           #+#    #+#             */
/*   Updated: 2021/06/20 17:10:51 by lbrandy          ###   ########.fr       */
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

int	fill_stack(t_num *stack_b, char *str[], int num)
{
	int i;
	int mass[num];
	int numeric;

	i = 1;
	while (i < num)
	{
		numeric = ft_atoi(str[i]);
		mass[i - 1] = numeric;
		if (check_repeats(numeric, mass, i) == 0)
			return (0);
		stack_b[i - 1].numeric = numeric;
		i++;
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
	if (fill_stack(stacks->stack_b, argv, argc) == 0)
		return (2);
	int i = 0;
	indexing(stacks->stack_b, argc);
	while (i < argc - 1)
	{
		printf("number is %d index is %d\n", stacks->stack_b[i].numeric, stacks->stack_b[i].index);
		i++;
	}
	return (0);
}
