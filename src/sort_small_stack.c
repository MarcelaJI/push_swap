#include "../include/push_swap.h"

void	sort_small_stack(t_state *state)
{
	int	min_index;

	if (state->size_a == 2)
	{
		if (state->stack_a->content > state->stack_a->next->content)
			ft_sa(state);
		return ;
	}
	while (state->size_a > 3)
	{
		min_index = find_lowest_index_position(state->stack_a);
		if (min_index == 0)
			ft_pb(state);
		else if (min_index <= state->size_a / 2)
			ft_ra(state);
		else
			ft_rra(state);
	}
	sort_three(state);
	while (state->size_b > 0)
		ft_pa(state);
}
