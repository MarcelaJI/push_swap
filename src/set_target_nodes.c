#include "../include/push_swap.h"

static t_stack	*get_target(t_stack *b_node, t_stack *stack_a)
{
	t_stack	*target;
	long	best_diff;
	long	current_diff;

	target = NULL;
	best_diff = (long)INT_MAX + 1;
	while (stack_a)
	{
		current_diff = (long)stack_a->content - (long)b_node->content;
		if (current_diff > 0 && current_diff < best_diff)
		{
			best_diff = current_diff;
			target = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (target);
}

void	set_target_nodes(t_state *state)
{
	t_stack	*b_node;

	b_node = state->stack_b;
	while (b_node)
	{
		b_node->target_node = get_target(b_node, state->stack_a);
		if (!b_node->target_node)
			b_node->target_node = find_min_node(state->stack_a);
		b_node = b_node->next;
	}
}







