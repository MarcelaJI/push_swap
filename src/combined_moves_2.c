/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:12:02 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 18:17:08 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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
