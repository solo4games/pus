#include <iostream>
#include <stdio.h>

typedef struct	s_num
{
	int		numeric;
	int		index;
	int		keep_in_stack_a;
}				t_num;

typedef struct	s_stacks
{
	t_num* stack_a;
	t_num* stack_b;
	int top_a;
	int top_b;
}				t_stacks;

void rra(t_num* stack_a, int top_a)
{
	if (top_a > 1)
	{
		t_num temp;
		temp = stack_a[0];
		for (int i = 0; i < top_a - 1; i++)
			stack_a[i] = stack_a[i + 1];
		stack_a[top_a - 1] = temp;
	}
}

void rrb(t_num* stack_b, int top_b)
{
	if (top_b > 1)
	{
		t_num temp;
		temp = stack_b[0];
		for (int i = 0; i < top_b - 1; i++)
			stack_b[i] = stack_b[i + 1];
		stack_b[top_b - 1] = temp;
	}
}

void rrr(t_stacks* stacks)
{
	rra(stacks->stack_a, stacks->top_a);
	rrb(stacks->stack_b, stacks->top_b);
}

void ra(t_num* stack_a, int top_a)
{
	if (top_a > 1)
	{
		t_num temp;
		temp = stack_a[top_a - 1];
		for (int i = top_a - 1; i > 0; i--)
			stack_a[i] = stack_a[i - 1];
		stack_a[0] = temp;
	}
}

void rb(t_num* stack_b, int top_b)
{
	if (top_b > 1)
	{
		t_num temp;
		temp = stack_b[top_b - 1];
		for (int i = top_b - 1; i > 0; i--)
			stack_b[i] = stack_b[i - 1];
		stack_b[0] = temp;
	}
}

void rr(t_stacks* stacks)
{
	ra(stacks->stack_a, stacks->top_a);
	rb(stacks->stack_b, stacks->top_b);
}

void pa(t_stacks* stacks)
{
	if (stacks->top_b != 0)
	{
		int top_b = stacks->top_b;
		int top_a = stacks->top_a;
		stacks->stack_a[top_a] = stacks->stack_b[top_b - 1];
		stacks->top_a++;
		stacks->top_b--;
	}
}

void pb(t_stacks* stacks)
{
	if (stacks->top_a != 0)
	{
		int top_b = stacks->top_b;
		int top_a = stacks->top_a;
		stacks->stack_b[top_b] = stacks->stack_a[top_a - 1];
		stacks->top_b++;
		stacks->top_a--;
	}
}

void sa(t_num* stack_a, int top_a)
{
	if (top_a > 1)
	{
		t_num temp;
		temp = stack_a[top_a - 1];
		stack_a[top_a - 1] = stack_a[top_a - 2];
		stack_a[top_a - 2] = temp;
	}
}

void sb(t_num* stack_b, int top_b)
{
	if (top_b > 1)
	{
		t_num temp;
		temp = stack_b[top_b - 1];
		stack_b[top_b - 1] = stack_b[top_b - 2];
		stack_b[top_b - 2] = temp;
	}
}

void ss(t_stacks* stacks)
{
	sa(stacks->stack_a, stacks->top_a);
	sb(stacks->stack_b, stacks->top_b);
}

int main()
{
	t_stacks* stacks;
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	stacks->stack_a = (t_num*)malloc(4 * sizeof(t_num));
	stacks->stack_b = (t_num*)malloc(4 * sizeof(t_num));
	stacks->top_a = 0;
	stacks->top_b = 0;
	for (int i = 0; i < 3; i++)
	{
		stacks->stack_a[i].numeric = i;
		stacks->stack_b[i].numeric = i + 3;
		stacks->top_a++;
		stacks->top_b++;
	}
	for (int i = 2; i > -1; i--)
	{
		std::cout << "stack_a - " << stacks->stack_a[i].numeric << std::endl;
		std::cout << "stack_b - " << stacks->stack_b[i].numeric << std::endl;
	}
	sa(stacks->stack_a, stacks->top_a);
	sb(stacks->stack_b, stacks->top_b);
	for (int i = 2; i > -1; i--)
	{
		std::cout << "stack_a - " << stacks->stack_a[i].numeric << std::endl;
		std::cout << "stack_b - " << stacks->stack_b[i].numeric << std::endl;
	}
	ss(stacks);
	for (int i = 2; i > -1; i--)
	{
		std::cout << "stack_a - " << stacks->stack_a[i].numeric << std::endl;
		std::cout << "stack_b - " << stacks->stack_b[i].numeric << std::endl;
	}
	rra(stacks->stack_a, stacks->top_a);
	for (int i = 2; i > -1; i--)
		std::cout << "stack_a - " << stacks->stack_a[i].numeric << std::endl;
	//pa(stacks);
	//std::cout << "top_a - " << stacks->stack_a[stacks->top_a - 1].numeric << std::endl;
	//std::cout << "top_b - " << stacks->stack_b[stacks->top_b - 1].numeric << std::endl;
}
