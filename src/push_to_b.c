#include "../include/push_swap.h"

void	push_all_but_three(t_state *state)
{
	while (state->size_a > 3)
	{
		set_index(state->stack_a);
		set_index(state->stack_b);
		set_above_median(state->stack_a, state->size_a);
		set_above_median(state->stack_b, state->size_b);
		set_target_node(state);
		set_cheapest_node(state);
		execute_cheapest_move(state);
	}
}

void	move_all_but_three(t_state *state)
{
	while (state->size_a > 3)
	{
		set_index(state->stack_a);
		set_index(state->stack_b);
		set_target_node(state);
		set_above_median(state->stack_a, state->size_a);
		set_above_median(state->stack_b, state->size_b);
		set_cheapest_node(state);
		execute_cheapest_move(state);
	}
}