/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:35:03 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 17:35:08 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_cheapest_node(t_stack *stack_b)
{
	t_stack	*cheapest;
	t_stack	*current;

	cheapest = NULL;
	current = stack_b;
	while (current)
	{
		if (cheapest == NULL
			|| current->operation_cost < cheapest->operation_cost)
			cheapest = current;
		current = current->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
	return (cheapest);
}
