/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:39 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 17:36:45 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_stack_a_to_top(t_state *state, t_stack *node)
{
	while (state->stack_a != node)
	{
		if (node->is_above_median)
			ft_ra(state);
		else
			ft_rra(state);
	}
}

void	move_stack_b_to_top(t_state *state, t_stack *node)
{
	while (state->stack_b != node)
	{
		if (node->is_above_median)
			ft_rb(state);
		else
			ft_rrb(state);
	}
}
