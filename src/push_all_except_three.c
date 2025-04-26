#include "../include/push_swap.h"

static int find_median_value(t_stack *stack, int size)
{
	int		*values;
	t_stack	*tmp;
	int		i, median;
	
	values = malloc(sizeof(int) * size);
	if (!values)
		ft_puterror();
	tmp = stack;
	i = 0;
	while (tmp)
	{
		values[i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_sort_int_tab(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

void	push_all_except_three(t_state *state)
{
	int pushed;
	int median;

	pushed = 0;
	median = find_median_value(state->stack_a, state->size_a);

	while (state->size_a > 6 && pushed < state->size_a / 2)
	{
		if (state->stack_a->content <= median)
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


