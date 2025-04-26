#include "../include/push_swap.h"

static t_stack	*get_best_target(t_stack *a_node, t_stack *stack_b)
{
	t_stack	*best_target;
	long	best_diff;
	long	current_diff;

	best_target = NULL;
	best_diff = __LONG_MAX__;

	while (stack_b)
	{
		current_diff = (long)a_node->content - (long)stack_b->content;
		if (current_diff > 0 && current_diff < best_diff)
		{
			best_diff = current_diff;
			best_target = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (best_target);
}

void	set_target_nodes(t_state *state)
{
	t_stack	*b_node;
	t_stack	*target;

	b_node = state->stack_b;
	while (b_node)
	{
		target = get_best_target(b_node, state->stack_a);
		if (!target)
			target = find_min_node(state->stack_a);
		b_node->target_node = target;
		b_node = b_node->next;
	}
}

