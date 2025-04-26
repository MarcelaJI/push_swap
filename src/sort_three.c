#include "../include/push_swap.h"

void	sort_three(t_state *state)
{
	int	first;
	int	second;
	int	third;

	if (state->size_a != 3)
		return ;
	first = state->stack_a->content;
	second = state->stack_a->next->content;
	third = state->stack_a->next->next->content;

	if (first > second && second < third && first < third)
		ft_sa(state);
	else if (first > second && second > third)
	{
		ft_sa(state);
		ft_rra(state);
	}
	else if (first > second && second < third && first > third)
		ft_ra(state);
	else if (first < second && second > third && first < third)
	{
		ft_sa(state);
		ft_ra(state);
	}
	else if (first < second && second > third && first > third)
		ft_rra(state);
}



