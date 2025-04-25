
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

int		find_lowest_index_position(t_stack *stack)
{
	int		pos;
	int		lowest_index;
	int		lowest_pos;
	t_stack	*temp;

	pos = 0;
	lowest_pos = 0;
	lowest_index = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (lowest_pos);
}

void	sort_small_stack(t_state *state)
{
	int	pos;

	while (state->size_a > 3)
	{
		pos = find_lowest_index_position(state->stack_a);
		if (pos <= state->size_a / 2)
			while (pos-- > 0)
				ft_ra(state);
		else
			while (pos++ < state->size_a)
				ft_rra(state);
		ft_pb(state);
	}
	sort_three(state);
	while (state->size_b > 0)
		ft_pa(state);
}

