/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:52 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 18:25:30 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sb(t_state *state)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!state->stack_b || !state->stack_b->next)
		return ;
	first = state->stack_b;
	second = state->stack_b->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	temp = first->index;
	first->index = second->index;
	second->index = temp;
	ft_printf("sb\n");
}

void	ft_rb(t_state *state)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (!state->stack_b || !state->stack_b->next)
		return ;
	temp = state->stack_b;
	state->stack_b = state->stack_b->next;
	state->stack_b->prev = NULL;
	last_node = state->stack_b;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = temp;
	temp->prev = last_node;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	ft_rrb(t_state *state)
{
	t_stack		*last;
	t_stack		*second_last;

	if (!state->stack_b || !state->stack_b->next)
		return ;
	last = state->stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = state->stack_b;
	state->stack_b->prev = last;
	state->stack_b = last;
	last->prev = NULL;
	ft_printf("rrb\n");
}
