/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_except_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:49:29 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/29 09:32:06 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_median(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;
	int		median;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_sort_int_tab(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	push_all_except_three(t_state *state)
{
	int	pushed;
	int	size;
	int	median;

	pushed = 0;
	size = state->size_a;
	median = get_median(state->stack_a, size);
	while (state->size_a > 6 && pushed < size / 2)
	{
		if (state->stack_a->content < median)
		{
			ft_pb(state);
			pushed++;
		}
		else
			ft_ra(state);
	}
	while (state->size_a > 3)
		ft_pb(state);
}
