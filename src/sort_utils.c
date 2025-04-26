#include "../include/push_swap.h"

void	set_median(t_stack *stack, int size)
{
	int		median;
	t_stack	*current;

	if (!stack)
		return ;
	median = size / 2;
	current = stack;
	while (current)
	{
		if (current->index <= median)
			current->is_above_median = 1;
		else
			current->is_above_median = 0;
		current = current->next;
	}
}

int	find_lowest_index_position(t_stack *stack)
{
	int	lowest_index;
	int	position;
	int	pos_counter;
	t_stack	*current;

	current = stack;
	lowest_index = current->index;
	position = 0;
	pos_counter = 0;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			position = pos_counter;
		}
		pos_counter++;
		current = current->next;
	}
	return (position);
}
