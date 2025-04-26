/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:55:42 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 18:05:23 by ingjimen         ###   ########.fr       */
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

	stack = NULL;
	if (size == 0 || arr == NULL)
		return (NULL);
	i = 0;
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
		ft_printf("Índex: %d\n", stack->index);
		ft_printf("Above median? %d\n", stack->is_above_median);
		stack = stack->next;
	}
}

void	set_index(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}
