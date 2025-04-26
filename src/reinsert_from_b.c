/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert_from_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 17:50:36 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reinsert_from_b(t_state *state)
{
	t_stack	*cheapest;

	set_index(state->stack_a);
	set_index(state->stack_b);
	set_above_median(state->stack_a, state->size_a);
	set_above_median(state->stack_b, state->size_b);
	set_target_nodes(state);
	set_costs(state);
	cheapest = find_cheapest_node(state->stack_b);
	if (!cheapest)
		return ;
	move_stack_b_to_top(state, cheapest);
	move_stack_a_to_top(state, cheapest->target_node);
	ft_pa(state);
}
