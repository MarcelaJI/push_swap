
#include "../include/push_swap.h"

static t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static t_stack	*get_best_target(t_stack *a_node, t_stack *stack_b)
{
	t_stack	*b_node;
	t_stack	*best_target;
	int		best_diff;
	int		diff;

	best_diff = INT_MAX;
	best_target = NULL;
	b_node = stack_b;
	while (b_node)
	{
		if (b_node->content > a_node->content)
		{
			diff = b_node->content - a_node->content;
			if (diff < best_diff)
			{
				best_diff = diff;
				best_target = b_node;
			}
		}
		b_node = b_node->next;
	}
	if (!best_target)
		best_target = find_min_node(stack_b);
	return (best_target);
}

void	set_target_node(t_state *state)
{
	t_stack	*a_node;

	a_node = state->stack_a;
	while (a_node)
	{
		a_node->target_node = get_best_target(a_node, state->stack_b);
		a_node = a_node->next;
	}
}

// void	print_target_nodes(t_stack *stack_a)
// {

// 	while (stack_a)
// 	{
// 		if (stack_a->target_node)
// 			ft_printf("Nodo A: %d -> Target B: %d: %d\n",
// 				stack_a->content, stack_a->target_node->content);
// 		else
// 			ft_printf("Nodo A: %d -> Target b: (null)\n",
// 				stack_a->content);
// 		stack_a = stack_a->next;
// 	}
// }

void	set_above_median(t_stack *stack, int size)
{
	int	median;
	int	i;

	median = size / 2;
	i = 0;
	while (stack)
	{
		if (i < median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i = i + 1;
	}
}
