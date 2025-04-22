
#include "../include/push_swap.h"

static void	swap_top_two(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	first = stack;
	second = stack->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	temp = first->index;
	first->index = second->index;
	second->index = temp;
}

void	ft_ss(t_state *state)
{
	if (state->stack_a && state->stack_a->next)
		swap_top_two(state->stack_a);
	if (state->stack_b && state->stack_b->next)
		swap_top_two(state->stack_b);
	ft_printf("ss\n");
}


