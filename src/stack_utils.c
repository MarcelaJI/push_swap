/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:55:42 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/17 12:16:37 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = 0;
	node->is_cheapest = 0;
	node->is_above_median = 0;
	node->operation_cost = 0;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_stack_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
}

t_stack	*array_to_stack(int *arr, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*node;

	i = 0;
	stack = NULL;
	if (size == 0 || arr == NULL)
		return (NULL);
	while (i < size)
	{
		node = create_stack_node(arr[i]);
		if (!node)
		{
			free_stack(&stack);
			return (NULL);
		}
		append_stack_node(&stack, node);
		i++;
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Nodo: %d\n", stack->content);
		stack = stack->next;
	}
}