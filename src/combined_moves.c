#include "../include/push_swap.h"

static void	swap_top_two(t_stack *stack)
{
	t_stack *first;
	t_stack *second;
	int		temp_content;
	int		temp_index;

	if (!stack || !stack->next)
		return;

	first = stack;
	second = stack->next;

	temp_content = first->content;
	first->content = second->content;
	second->content = temp_content;

	temp_index = first->index;
	first->index = second->index;
	second->index = temp_index;
}

void	ft_ss(t_state *state)
{
	if ((state->stack_a && state->stack_a->next) ||
		(state->stack_b && state->stack_b->next))
	{
		if (state->stack_a && state->stack_a->next)
			swap_top_two(state->stack_a);
		if (state->stack_b && state->stack_b->next)
			swap_top_two(state->stack_b);
		ft_printf("ss\n");
	}
}

static void	rotate_stack(t_stack **stack)
{
	t_stack *temp;
	t_stack *last_node;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;

	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;

	last_node->next = temp;
	temp->prev = last_node;
	temp->next = NULL;
}

void	ft_rr(t_state *state)
{
	if (state->stack_a && state->stack_a->next)
		rotate_stack(&state->stack_a);
	if (state->stack_b && state->stack_b->next)
		rotate_stack(&state->stack_b);
	ft_printf("rr\n");
}

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack *last;
	t_stack *second_last;

	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev = NULL;
}

void	ft_rrr(t_state *state)
{
	if (state->stack_a && state->stack_a->next)
		reverse_rotate_stack(&state->stack_a);
	if (state->stack_b && state->stack_b->next)
		reverse_rotate_stack(&state->stack_b);
	ft_printf("rrr\n");
}






