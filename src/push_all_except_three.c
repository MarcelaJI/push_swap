#include "../include/push_swap.h"

void	push_all_except_three(t_state *state)
{
	int pushed;
	int size;
	int median;

	pushed = 0;
	size = state->size_a;
	median = size / 2;

	while (size > 6 && pushed < median)
	{
		if (state->stack_a->content <= median)
		{
			ft_pb(state);
			pushed++;
		}
		else
			ft_ra(state);
		size = state->size_a;
	}

	while (state->size_a > 3)
		ft_pb(state);
}




