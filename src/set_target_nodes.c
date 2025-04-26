#include "../include/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	swapped;

	if (!tab || size < 2)
		return ;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}


static t_stack	*find_best_target(t_stack *stack_a, int b_content)
{
	t_stack	*best_target;
	t_stack	*current;

	best_target = NULL;
	current = stack_a;
	while (current)
	{
		if (current->content > b_content)
		{
			if (!best_target || current->content < best_target->content)
				best_target = current;
		}
		current = current->next;
	}
	if (!best_target)
	{
		current = stack_a;
		while (current)
		{
			if (!best_target || current->content < best_target->content)
				best_target = current;
			current = current->next;
		}
	}
	return (best_target);
}

void	set_target_nodes(t_state *state)
{
	t_stack	*b_node;

	b_node = state->stack_b;
	while (b_node)
	{
		b_node->target_node = find_best_target(state->stack_a, b_node->content);
		b_node = b_node->next;
	}
}


