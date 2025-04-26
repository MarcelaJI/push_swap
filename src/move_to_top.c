#include "../include/push_swap.h"

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

