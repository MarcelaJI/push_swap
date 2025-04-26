/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_above_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:42 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 18:10:51 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_above_median(t_stack *stack, int size)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	median = size / 2;
	i = 0;
	while (stack)
	{
		if (i <= median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i++;
	}
}
