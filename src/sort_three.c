/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:51:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 17:51:13 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_state *state)
{
	int	first;
	int	second;
	int	third;

	if (state->size_a != 3)
		return ;
	first = state->stack_a->content;
	second = state->stack_a->next->content;
	third = state->stack_a->next->next->content;
	if (first > second && second < third && first < third)
		ft_sa(state);
	else if (first > second && second > third)
	{
		ft_sa(state);
		ft_rra(state);
	}
	else if (first > second && second < third && first > third)
		ft_ra(state);
	else if (first < second && second > third && first < third)
	{
		ft_sa(state);
		ft_ra(state);
	}
	else if (first < second && second > third && first > third)
		ft_rra(state);
}
