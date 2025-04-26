/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:50 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 17:50:55 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_costs(t_state *state)
{
	t_stack	*b_node;
	int		size_a;
	int		size_b;

	size_a = state->size_a;
	size_b = state->size_b;
	b_node = state->stack_b;
	while (b_node)
	{
		b_node->operation_cost = b_node->index;
		if (b_node->index > size_b / 2)
			b_node->operation_cost = size_b - b_node->index;
		if (b_node->target_node->index <= size_a / 2)
			b_node->operation_cost += b_node->target_node->index;
		else
			b_node->operation_cost += size_a - b_node->target_node->index;
		b_node = b_node->next;
	}
}
