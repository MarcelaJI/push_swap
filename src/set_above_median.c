/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_above_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:42 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/29 00:06:28 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void set_above_median(t_stack *stack, int size)
{
	int i;
	int median;
	t_stack *current;

	if (!stack)
		return ;
	current = stack;
	median = size / 2;
	i = 0;
	while (current)
	{
		current->is_above_median = (i <= median);
		current = current->next;
		i++;
	}
}

