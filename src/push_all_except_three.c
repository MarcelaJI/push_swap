
#include "../include/push_swap.h"

void	push_all_except_three(t_state *state)
{
	int	pushed;
	int	total_size;
	int	median;

	pushed = 0;
	total_size = state->size_a;
	median = total_size / 2;

	while (total_size > 6 && pushed < median)
	{
		if (state->stack_a->index <= median)
		{
			ft_pb(state);
			pushed++;
		}
		else
			ft_ra(state);
	}
	while (state->size_a > 3)
		ft_pb(state);
}

