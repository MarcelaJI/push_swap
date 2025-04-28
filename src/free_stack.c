/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:17:46 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/28 10:43:26 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_strs_arr(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	free_state(t_state **state)
{
	if (!state || !*state)
		return ;
	free_stack(&(*state)->stack_a);
	free_stack(&(*state)->stack_b);
	free(*state);
	*state = NULL;
}
