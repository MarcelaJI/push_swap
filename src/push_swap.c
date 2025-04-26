/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:23:55 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 18:51:46 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = parse_data(argv);
		if (!stack_a)
			return (EXIT_FAILURE);
		if (!ft_is_sorted(stack_a))
			sort(stack_a);
		else
			free_stack(&stack_a);
	}
	return (EXIT_SUCCESS);
}
