#include "../include/push_swap.h"

void	finish_rotation(t_state *state)
{
	int		lowest_pos;
	int		size;
	t_stack	*stack;

	stack = state->stack_a;
	size = state->size_a;
	set_index(stack);
	lowest_pos = find_lowest_index_position(stack);

	if (lowest_pos <= size / 2)
	{
		while (stack->index != 0)
			ft_ra(state);
	}
	else
	{
		while (stack->index != 0)
			ft_rra(state);
	}
}

void	sort(t_stack *stack_a)
{
	t_state	state;

	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.size_a = 0;
	state.size_b = 0;
	t_stack *tmp = stack_a;
	while (tmp)
	{
		state.size_a++;
		tmp = tmp->next;
	}
	set_index(state.stack_a);
	if (state.size_a <= 3)
	{
		sort_three(&state);
		return ;
	}
	else if (state.size_a <= 5)
	{
		sort_small_stack(&state);
		return ;
	}
	push_all_except_three(&state);
	sort_three(&state);
	while (state.size_b > 0)
		reinsert_from_b(&state);
	finish_rotation(&state);
}








