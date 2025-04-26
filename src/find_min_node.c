#include "../include/push_swap.h"

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->content < min_node->content)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}
