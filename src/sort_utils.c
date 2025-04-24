
#include "../include/push_swap.h"

void	sort_three(t_state *state)
{
	int	a;
	int	b;
	int	c;

	a = state->stack_a->content;
	b = state->stack_a->next->content;
	c = state->stack_a->next->next->content;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		ft_sa(state);
		ft_ra(state);
	}
	else if (b < a && a < c)
		ft_sa(state);
	else if (c < a && a < b)
		ft_rra(state);
	else if (b < c && c < a)
		ft_ra(state);
	else if (c < b && b < a)
	{
		ft_sa(state);
		ft_rra(state);
	}
}
