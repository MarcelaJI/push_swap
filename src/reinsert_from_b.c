#include "../include/push_swap.h"

static t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (stack->target_node && (!cheapest || stack->operation_cost < cheapest->operation_cost))
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	reinsert_from_b(t_state *state)
{
	t_stack	*cheapest;

	set_index(state->stack_a);
	set_index(state->stack_b);
	set_above_median(state->stack_a, state->size_a);
	set_above_median(state->stack_b, state->size_b);
	set_target_nodes(state);
	set_costs(state);

	cheapest = get_cheapest_node(state->stack_b);
	if (!cheapest || !cheapest->target_node)
		return ;

	move_stack_b_to_top(state, cheapest);
	move_stack_a_to_top(state, cheapest->target_node);
	ft_pa(state);
}


