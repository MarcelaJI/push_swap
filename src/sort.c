#include "../include/push_swap.h"

static void	finish_rotation(t_state *state)
{
	int	lowest_pos;
	t_stack	*stack;
	int	size;

	stack = state->stack_a;
	size = state->size_a;
	set_index(stack);
	lowest_pos = find_lowest_index_position(stack);
	while (stack->index != 0)
	{
		if (lowest_pos <= size / 2)
			ft_ra(state);
		else
			ft_rra(state);
	}
}

static void	initialize_state(t_state *state, t_stack *stack_a)
{
	t_stack	*tmp;

	state->stack_a = stack_a;
	state->stack_b = NULL;
	state->size_a = 0;
	state->size_b = 0;
	tmp = stack_a;
	while (tmp && ++(state->size_a))
		tmp = tmp->next;
	set_index(state->stack_a);
}

void	sort(t_stack *stack_a)
{
	t_state	state;

	initialize_state(&state, stack_a);
	if (state.size_a <= 2)
		sort_small_stack(&state);
	else if (state.size_a == 3)
		sort_three(&state);
	else if (state.size_a <= 5)
		sort_small_stack(&state);
	else
	{
		push_all_except_three(&state);
		sort_three(&state);
		while (state.size_b > 0)
			reinsert_from_b(&state);
		finish_rotation(&state);
	}
	free_stack(&(state.stack_a));
	free_stack(&(state.stack_b));
}


