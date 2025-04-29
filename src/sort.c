/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:42:10 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/29 09:32:32 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	finish_rotation(t_state *state)
{
	t_stack	*min_node;

	set_index(state->stack_a);
	min_node = find_min_node(state->stack_a);
	set_above_median(state->stack_a, state->size_a);
	while (state->stack_a != min_node)
	{
		if (min_node->is_above_median)
			ft_ra(state);
		else
			ft_rra(state);
	}
}

static void	initialize_state(t_state *state, t_stack *stack_a)
{
	t_stack	*tmp;

	state->stack_a = stack_a;
	state->stack_b = NULL;
	state->size_a = 0;
	state->size_b = 0;
	tmp = stack_a;
	while (tmp)
	{
		state->size_a++;
		tmp = tmp->next;
	}
}

void	sort(t_stack *stack_a)
{
	t_state	state;

	initialize_state(&state, stack_a);
	if (state.size_a <= 2)
	{
		if (!ft_is_sorted(state.stack_a))
			ft_sa(&state);
		free_stack(&(state.stack_a));
	}
	else if (state.size_a == 3)
	{
		sort_three(&state);
		free_stack(&(state.stack_a));
	}
	else
	{
		push_all_except_three(&state);
		sort_three(&state);
		while (state.size_b > 0)
			reinsert_from_b(&state);
		finish_rotation(&state);
		free_stack(&(state.stack_a));
	}
}
