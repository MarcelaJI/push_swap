#include "../include/push_swap.h"

static int	cost_to_top(int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

void	set_costs(t_state *state)
{
	t_stack	*b_node;
	int		cost_a;
	int		cost_b;

	b_node = state->stack_b;
	while (b_node)
	{
		if (b_node->target_node)
			cost_a = cost_to_top(b_node->target_node->index, state->size_a);
		else
			cost_a = 0;
		cost_b = cost_to_top(b_node->index, state->size_b);
		b_node->operation_cost = cost_a + cost_b;
		b_node = b_node->next;
	}
}

