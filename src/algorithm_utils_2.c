
#include "../include/push_swap.h"

static int	calculate_costs(t_state *state, t_stack *node)
{
	int cost_a;
	int cost_b;

	if (node->is_above_median)
		cost_a = state->size_a - node->index;
	else
		cost_a = node->index;

	if (node->target_node->is_above_median)
		cost_b = state->size_b - node->target_node->index;
	else
		cost_b = node->target_node->index;

	node->operation_cost = cost_a + cost_b;
	return (node->operation_cost);
}

void	set_cheapest_node(t_state *state)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		best_cost;
	int		total_cost;

	current = state->stack_a;
	best_cost = INT_MAX;
	cheapest = NULL;
	while (current)
	{
		current->is_cheapest = 0;
		total_cost = calculate_costs(state, current);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
}

void	move_stack_a_to_top(t_state *state, t_stack *node)
{
	while (state->stack_a != node)
	{
		if (node->is_above_median)
			ft_ra(state);
		else
			ft_rra(state);
	}
}

void	move_stack_b_to_top(t_state *state, t_stack *node)
{
	while (state->stack_b != node)
	{
		if (node->is_above_median)
			ft_rb(state);
		else
			ft_rrb(state);
	}
}

void	execute_cheapest_move(t_state *state)
{
	t_stack	*cheapest;

	cheapest = state->stack_a;
	while (cheapest && !cheapest->is_cheapest)
		cheapest = cheapest->next;
	if (!cheapest)
		return ;
	while (state->stack_a != cheapest || state->stack_b != cheapest->target_node)
	{
		if (cheapest->is_above_median && cheapest->target_node->is_above_median)
			ft_rr(state);
		else if (!cheapest->is_above_median && !cheapest->target_node->is_above_median)
			ft_rrr(state);
		else
		{
			move_stack_a_to_top(state, cheapest);
			move_stack_b_to_top(state, cheapest->target_node);
		}
	}
	ft_pb(state);
}


